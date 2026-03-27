/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 01:05:14 by echiu             #+#    #+#             */
/*   Updated: 2024/04/24 16:02:49 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Low z: purple — high z: blue (height from map file) */
# define FDF_GRAD_R0 0x6B
# define FDF_GRAD_G0 0x2D
# define FDF_GRAD_B0 0x9E
# define FDF_GRAD_R1 0x1E
# define FDF_GRAD_G1 0x90
# define FDF_GRAD_B1 0xFF

void	put_pixel_img(t_data *data, int x, int y, int color)
{
	char	*dest;

	if (x >= 0 && y >= 0 && x < data->w && y < data->h)
	{
		dest = data->addr + (y * data->line_len + x * (data->bpp / 8));
#ifdef __APPLE__
		/*
		 * MLX42 matches OpenGL GL_RGBA: first byte R, then G, B, A.
		 * A little-endian uint32 store would lay out A,B,G,R — wrong hue (often orange).
		 */
		dest[0] = (char)((color >> 24) & 0xFF);
		dest[1] = (char)((color >> 16) & 0xFF);
		dest[2] = (char)((color >> 8) & 0xFF);
		dest[3] = (char)(color & 0xFF);
#else
		*(unsigned int *)dest = color;
#endif
	}
}

void	ft_clear_img(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (y++ < data->h)
	{
		x = -1;
		while (x++ < data->w)
			put_pixel_img(data, x, y, FDF_COLOR_CLEAR);
	}
}

static int	get_aa_color(int color, double brightness)
{
	int	r;
	int	g;
	int	b;
	int	a;

	if (brightness < 0.0)
		brightness = 0.0;
	if (brightness > 1.0)
		brightness = 1.0;
#ifdef __APPLE__
	/* MLX42: R high byte, A low byte */
	r = (int)(((color >> 24) & 0xFF) * brightness);
	g = (int)(((color >> 16) & 0xFF) * brightness);
	b = (int)(((color >> 8) & 0xFF) * brightness);
	a = (color & 0xFF);
	if (a == 0)
		a = 0xFF;
	return ((r << 24) | (g << 16) | (b << 8) | a);
#else
	/* MiniLibX-style 0x00RRGGBB used by original line drawing */
	r = (int)(((color >> 16) & 0xFF) * brightness);
	g = (int)(((color >> 8) & 0xFF) * brightness);
	b = (int)((color & 0xFF) * brightness);
	return ((r << 16) | (g << 8) | b);
#endif
}

static int	color_from_height(t_data *data, double z)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (z - data->z_min) / (data->z_max - data->z_min);
	if (t < 0.0)
		t = 0.0;
	if (t > 1.0)
		t = 1.0;
	r = (int)(FDF_GRAD_R0 + t * (FDF_GRAD_R1 - FDF_GRAD_R0));
	g = (int)(FDF_GRAD_G0 + t * (FDF_GRAD_G1 - FDF_GRAD_G0));
	b = (int)(FDF_GRAD_B0 + t * (FDF_GRAD_B1 - FDF_GRAD_B0));
#ifdef __APPLE__
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
#else
	return ((r << 16) | (g << 8) | b);
#endif
}

static double	z_interp(double x0, double x1, double z0, double z1, double x)
{
	if (fabs(x1 - x0) < 1e-9)
		return ((z0 + z1) * 0.5);
	return (z0 + (z1 - z0) * ((x - x0) / (x1 - x0)));
}

static int	ipart(double x)
{
	return ((int)floor(x));
}

static double	roundn(double x)
{
	return (floor(x + 0.5));
}

static double	fpart(double x)
{
	return (x - floor(x));
}

static double	rfpart(double x)
{
	return (1.0 - fpart(x));
}

static void	plot_aa(t_data *data, int steep, int x, int y, double brightness,
		int base_color)
{
	if (steep)
		put_pixel_img(data, y, x, get_aa_color(base_color, brightness));
	else
		put_pixel_img(data, x, y, get_aa_color(base_color, brightness));
}

void	ft_putline(t_data *data, int i, int j)
{
	double	x0;
	double	y0;
	double	x1;
	double	y1;
	double	z0;
	double	z1;
	double	tmp;
	double	dx;
	double	dy;
	double	gradient;
	double	xend;
	double	yend;
	double	xgap;
	double	intery;
	int		xpxl1;
	int		xpxl2;
	int		ypxl1;
	int		ypxl2;
	int		x;
	int		steep;

	x0 = data->tredi[i].x;
	y0 = data->tredi[i].y;
	x1 = data->tredi[j].x;
	y1 = data->tredi[j].y;
	z0 = data->todi[i].z;
	z1 = data->todi[j].z;
	steep = (ft_abs((int)(y1 - y0)) > ft_abs((int)(x1 - x0)));
	if (steep)
	{
		tmp = x0;
		x0 = y0;
		y0 = tmp;
		tmp = x1;
		x1 = y1;
		y1 = tmp;
	}
	if (x0 > x1)
	{
		tmp = x0;
		x0 = x1;
		x1 = tmp;
		tmp = y0;
		y0 = y1;
		y1 = tmp;
		tmp = z0;
		z0 = z1;
		z1 = tmp;
	}
	dx = x1 - x0;
	dy = y1 - y0;
	gradient = 0.0;
	if (dx != 0.0)
		gradient = dy / dx;
	xend = roundn(x0);
	yend = y0 + gradient * (xend - x0);
	xgap = rfpart(x0 + 0.5);
	xpxl1 = (int)xend;
	ypxl1 = ipart(yend);
	plot_aa(data, steep, xpxl1, ypxl1, rfpart(yend) * xgap,
		color_from_height(data, z_interp(x0, x1, z0, z1, (double)xpxl1)));
	plot_aa(data, steep, xpxl1, ypxl1 + 1, fpart(yend) * xgap,
		color_from_height(data, z_interp(x0, x1, z0, z1, (double)xpxl1)));
	intery = yend + gradient;
	xend = roundn(x1);
	yend = y1 + gradient * (xend - x1);
	xgap = fpart(x1 + 0.5);
	xpxl2 = (int)xend;
	ypxl2 = ipart(yend);
	plot_aa(data, steep, xpxl2, ypxl2, rfpart(yend) * xgap,
		color_from_height(data, z_interp(x0, x1, z0, z1, (double)xpxl2)));
	plot_aa(data, steep, xpxl2, ypxl2 + 1, fpart(yend) * xgap,
		color_from_height(data, z_interp(x0, x1, z0, z1, (double)xpxl2)));
	x = xpxl1 + 1;
	while (x < xpxl2)
	{
		plot_aa(data, steep, x, ipart(intery), rfpart(intery),
			color_from_height(data, z_interp(x0, x1, z0, z1, (double)x)));
		plot_aa(data, steep, x, ipart(intery) + 1, fpart(intery),
			color_from_height(data, z_interp(x0, x1, z0, z1, (double)x)));
		intery += gradient;
		x++;
	}
}

void	ft_placelines(t_data *data)
{
	data->i = 0;
	data->j = 1;
	data->k = 0;
	data->l = 1;
	data->m = data->c;
	while (data->k < data->r)
	{
		while ((data->i < data->c * data->l) && (data->j != data->c * data->l))
		{
			ft_putline(data, data->i, data->j);
			if (data->l != data->r)
				ft_putline(data, data->i, data->m);
			data->i++;
			data->j++;
			data->m++;
		}
		if ((data->i < data->c * data->l) && (data->j == data->c * data->l)
			&& (data->l != data->r))
			ft_putline(data, data->i, data->m);
		data->i++;
		data->j++;
		data->k++;
		data->l++;
		data->m++;
	}
}

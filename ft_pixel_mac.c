/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_mac.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:00:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 17:00:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_pack_rgb(int r, int g, int b)
{
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

int	fdf_scale_color(int color, double brightness)
{
	int	r;
	int	g;
	int	b;
	int	a;

	if (brightness < 0.0)
		brightness = 0.0;
	if (brightness > 1.0)
		brightness = 1.0;
	r = (int)(((color >> 24) & 0xFF) * brightness);
	g = (int)(((color >> 16) & 0xFF) * brightness);
	b = (int)(((color >> 8) & 0xFF) * brightness);
	a = (color & 0xFF);
	if (a == 0)
		a = 0xFF;
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

void	put_pixel_img(t_data *data, int x, int y, int color)
{
	char	*dest;

	if (x >= 0 && y >= 0 && x < data->w && y < data->h)
	{
		dest = data->addr + (y * data->line_len + x * (data->bpp / 8));
		dest[0] = (char)((color >> 24) & 0xFF);
		dest[1] = (char)((color >> 16) & 0xFF);
		dest[2] = (char)((color >> 8) & 0xFF);
		dest[3] = (char)(color & 0xFF);
	}
}

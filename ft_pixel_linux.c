/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_linux.c                                   :+:      :+:    :+:   */
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
	return ((r << 16) | (g << 8) | b);
}

int	fdf_scale_color(int color, double brightness)
{
	int	r;
	int	g;
	int	b;

	if (brightness < 0.0)
		brightness = 0.0;
	if (brightness > 1.0)
		brightness = 1.0;
	r = (int)(((color >> 16) & 0xFF) * brightness);
	g = (int)(((color >> 8) & 0xFF) * brightness);
	b = (int)((color & 0xFF) * brightness);
	return ((r << 16) | (g << 8) | b);
}

void	put_pixel_img(t_data *data, int x, int y, int color)
{
	char	*dest;

	if (x >= 0 && y >= 0 && x < data->w && y < data->h)
	{
		dest = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int *)dest = color;
	}
}

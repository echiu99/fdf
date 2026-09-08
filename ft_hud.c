/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:30:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 18:30:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define FDF_HUD_H 32

void	ft_hud_clear(t_data *data)
{
	(void)data;
}

static void	ft_hud_bar(t_data *data)
{
	int	x;
	int	y;
	int	bar;
	int	col;

	bar = data->h - FDF_HUD_H;
	col = fdf_pack_rgb(0x18, 0x18, 0x18);
	y = bar;
	while (y < data->h)
	{
		x = 0;
		while (x < data->w)
		{
			put_pixel_img(data, x, y, col);
			x++;
		}
		y++;
	}
}

void	ft_draw_hud(t_data *data)
{
	char	line[FDF_CMD_MAX + 2];

	if (!data->cmd_mode)
		return ;
	ft_hud_bar(data);
	line[0] = ':';
	ft_strlcpy(line + 1, data->cmd_buf, FDF_CMD_MAX + 1);
	ft_hud_putstr(data, 12, data->h - FDF_HUD_H + 8, line);
	ft_put_img(data);
}

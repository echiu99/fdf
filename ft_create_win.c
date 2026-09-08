/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:08:14 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 18:50:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(t_data *data, int i)
{
	ft_free_runtime(data);
	ft_destroy_mlx(data);
	if (i == 0)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}

void	ft_newwin(t_data *data)
{
	data->w = FDF_WIN_W;
	data->h = FDF_WIN_H;
	data->color = 0xFFFFFFFF;
	ft_init_window(data);
}

void	ft_newimg(t_data *data)
{
	data->dx = 0;
	data->dy = 0;
	data->low = 0;
	data->xhigh = 0;
	data->yhigh = 0;
	ft_init_image(data);
}

void	init_mlxdata(t_data *data)
{
	data->h = 0;
	data->w = 0;
	data->bpp = 0;
	data->endian = 0;
	data->line_len = 0;
	ft_newwin(data);
	ft_newimg(data);
}

int	close_event(t_data *data)
{
	close_win(data, 0);
	return (0);
}

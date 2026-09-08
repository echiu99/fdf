/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_linux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:00:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 18:50:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_destroy_mlx(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

static void	ft_fit_monitor(t_data *data)
{
	int	mw;
	int	mh;

	mw = 0;
	mh = 0;
	mlx_get_screen_size(data->mlx_ptr, &mw, &mh);
	if (mw <= 0 || mh <= 0)
		return ;
	if (data->w > mw - 64)
		data->w = mw - 64;
	if (data->h > mh - 96)
		data->h = mh - 96;
	if (data->w < 640)
		data->w = 640;
	if (data->h < 480)
		data->h = 480;
}

void	ft_init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	ft_fit_monitor(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->w, data->h, "FDF");
}

void	ft_init_image(t_data *data)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->w, data->h);
	data->addr = mlx_get_data_addr(data->img_ptr, &(data->bpp),
			&(data->line_len), &(data->endian));
}

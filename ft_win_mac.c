/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_mac.c                                       :+:      :+:    :+:   */
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
	mlx_delete_image((mlx_t *)data->mlx_ptr, (mlx_image_t *)data->img_ptr);
	mlx_terminate((mlx_t *)data->mlx_ptr);
}

static void	ft_fit_monitor(t_data *data)
{
	int32_t	mw;
	int32_t	mh;

	mw = 0;
	mh = 0;
	mlx_get_monitor_size(0, &mw, &mh);
	if (mw <= 0 || mh <= 0)
		return ;
	if (mw >= 2000)
		mw /= 2;
	if (mh >= 1400)
		mh /= 2;
	if (data->w > mw - 64)
		data->w = mw - 64;
	if (data->h > mh - 96)
		data->h = mh - 96;
	if (data->w < 640)
		data->w = 640;
	if (data->h < 480)
		data->h = 480;
	mlx_set_window_size((mlx_t *)data->mlx_ptr, data->w, data->h);
}

void	ft_init_window(t_data *data)
{
	data->mlx_ptr = mlx_init(data->w, data->h, "FDF", false);
	data->win_ptr = data->mlx_ptr;
	ft_fit_monitor(data);
}

void	ft_init_image(t_data *data)
{
	data->img_ptr = mlx_new_image((mlx_t *)data->mlx_ptr, data->w, data->h);
	data->addr = (char *)((mlx_image_t *)data->img_ptr)->pixels;
	data->bpp = 32;
	data->line_len = data->w * 4;
	data->endian = 0;
	mlx_image_to_window((mlx_t *)data->mlx_ptr,
		(mlx_image_t *)data->img_ptr, 0, 0);
}

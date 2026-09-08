/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_mac.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:00:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 17:00:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_destroy_mlx(t_data *data)
{
	mlx_delete_image((mlx_t *)data->mlx_ptr, (mlx_image_t *)data->img_ptr);
	mlx_terminate((mlx_t *)data->mlx_ptr);
}

void	ft_init_window(t_data *data)
{
	data->mlx_ptr = mlx_init(data->w, data->h, "FDF", false);
	data->win_ptr = data->mlx_ptr;
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

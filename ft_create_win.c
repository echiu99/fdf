/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:08:14 by echiu             #+#    #+#             */
/*   Updated: 2024/04/24 16:39:46 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(t_data *data, int i)
{
#ifdef __APPLE__
	mlx_delete_image((mlx_t *)data->mlx_ptr, (mlx_image_t *)data->img_ptr);
	mlx_terminate((mlx_t *)data->mlx_ptr);
#else
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
#endif
	if (i == 0)
	{
		free(data->todi);
		free(data->tredi);
	}
	if (i == 0)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}

void	ft_newwin(t_data *data)
{
	data->w = 1920;
	data->h = 1080;
	data->color = 0xFFFFFFFF;
#ifdef __APPLE__
	data->mlx_ptr = mlx_init(data->w, data->h, "FDF", false);
	data->win_ptr = data->mlx_ptr;
#else
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->w, data->h, "FDF");
#endif
}

void	ft_newimg(t_data *data)
{
	data->dx = 0;
	data->dy = 0;
	data->low = 0;
	data->xhigh = 0;
	data->yhigh = 0;
#ifdef __APPLE__
	data->img_ptr = mlx_new_image((mlx_t *)data->mlx_ptr, data->w, data->h);
	data->addr = (char *)((mlx_image_t *)data->img_ptr)->pixels;
	data->bpp = 32;
	data->line_len = data->w * 4;
	data->endian = 0;
	mlx_image_to_window((mlx_t *)data->mlx_ptr, (mlx_image_t *)data->img_ptr, 0, 0);
#else
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->w, data->h);
	data->addr = mlx_get_data_addr(data->img_ptr, &(data->bpp),
			&(data->line_len), &(data->endian));
#endif
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

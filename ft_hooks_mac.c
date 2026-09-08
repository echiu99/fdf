/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_mac.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:50:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 16:50:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdint.h>

void	read_keys_mac(mlx_key_data_t keydata, void *param)
{
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		read_keys((int)keydata.key, (t_data *)param);
}

void	close_event_mac(void *param)
{
	close_win((t_data *)param, 0);
}

void	scroll_hook_mac(double xdelta, double ydelta, void *param)
{
	t_data		*data;
	int32_t		mx;
	int32_t		my;

	(void)xdelta;
	data = (t_data *)param;
	if (ydelta == 0.0)
		return ;
	mlx_get_mouse_pos((mlx_t *)data->mlx_ptr, &mx, &my);
	if (ydelta > 0.0)
		ft_zoom_at(data, (int)mx, (int)my, FDF_ZOOM_WHEEL);
	else
		ft_zoom_at(data, (int)mx, (int)my, 1.0 / FDF_ZOOM_WHEEL);
}

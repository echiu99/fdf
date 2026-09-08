/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_mac.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:50:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 18:00:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdint.h>

void	read_keys_mac(mlx_key_data_t keydata, void *param)
{
	t_data	*data;
	int		key;
	int		shift;

	if (keydata.action != MLX_PRESS && keydata.action != MLX_REPEAT)
		return ;
	data = (t_data *)param;
	key = (int)keydata.key;
	shift = (keydata.modifier & MLX_SHIFT) != 0;
	if (data->cmd_mode)
	{
		ft_cmd_key(data, key, shift);
		return ;
	}
	if (key == MLX_KEY_SEMICOLON && shift)
		key = 58;
	read_keys(key, data);
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
	if (data->cmd_mode || ydelta == 0.0)
		return ;
	mlx_get_mouse_pos((mlx_t *)data->mlx_ptr, &mx, &my);
	if (ydelta > 0.0)
		ft_zoom_at(data, (int)mx, (int)my, FDF_ZOOM_WHEEL);
	else
		ft_zoom_at(data, (int)mx, (int)my, 1.0 / FDF_ZOOM_WHEEL);
}

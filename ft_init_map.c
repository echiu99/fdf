/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:00:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 18:00:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_cmd_state(t_data *data)
{
	data->hud_img = NULL;
	data->cmd_mode = 0;
	data->cmd_len = 0;
	data->cmd_buf[0] = '\0';
	data->map_path = NULL;
	data->todi = NULL;
	data->tredi = NULL;
	data->size = 0;
	data->r = 0;
	data->c = 0;
}

void	init_mapdata(t_data *data, char *map_path)
{
	ft_init_cmd_state(data);
	ft_scheme_apply(data, 0);
	ft_maps_scan(data);
	if (ft_load_map_coords(data, map_path) < 0)
	{
		ft_printf("Invalid or missing map: %s\n", map_path);
		close_win(data, 1);
	}
	data->map_path = ft_strdup(map_path);
	ft_compute_z_range(data);
	ft_alloc_view(data);
	data->angle_x = 0.0;
	data->angle_y = 0.0;
	data->scale = FDF_DEFAULT_SCALE;
	data->off_x = (double)data->w / 2.0;
	data->off_y = (double)data->h / 4.0;
	ft_rebuild_view(data);
}

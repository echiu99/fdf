/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_ctrl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:50:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 16:50:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_reset_view(t_data *data)
{
	data->angle_x = 0.0;
	data->angle_y = 0.0;
	data->scale = FDF_DEFAULT_SCALE;
	data->off_x = (double)data->w / 2.0;
	data->off_y = (double)data->h / 4.0;
	ft_rebuild_view(data);
	ft_redraw(data);
}

void	rotate_yaw(t_data *data, double delta)
{
	data->angle_y += delta;
	ft_rebuild_view(data);
	ft_redraw(data);
}

void	rotate_pitch(t_data *data, double delta)
{
	data->angle_x += delta;
	ft_rebuild_view(data);
	ft_redraw(data);
}

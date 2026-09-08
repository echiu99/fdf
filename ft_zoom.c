/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:50:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 16:50:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom_at(t_data *data, int mx, int my, double factor)
{
	double	old;
	double	neu;

	old = data->scale;
	neu = old * factor;
	if (neu < FDF_SCALE_MIN)
		neu = FDF_SCALE_MIN;
	if (neu > FDF_SCALE_MAX)
		neu = FDF_SCALE_MAX;
	factor = neu / old;
	if (fabs(factor - 1.0) < 1e-9)
		return ;
	data->off_x = (double)mx - ((double)mx - data->off_x) * factor;
	data->off_y = (double)my - ((double)my - data->off_y) * factor;
	data->scale = neu;
	ft_rebuild_view(data);
	ft_redraw(data);
}

void	scale_down(t_data *data)
{
	ft_zoom_at(data, data->w / 2, data->h / 2, 0.5);
}

void	scale_up(t_data *data)
{
	ft_zoom_at(data, data->w / 2, data->h / 2, 2.0);
}

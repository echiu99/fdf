/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_project.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:50:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 16:50:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_alloc_view(t_data *data)
{
	data->tredi = (t_coords *)malloc(sizeof(t_coords) * data->size);
	if (!data->tredi)
	{
		free(data->todi);
		data->todi = NULL;
		close_win(data, 1);
	}
}

static void	ft_project_one(t_data *data, unsigned int i, double cx, double cy)
{
	double	v[3];
	double	t;

	v[0] = data->todi[i].x - cx;
	v[1] = data->todi[i].y - cy;
	v[2] = data->todi[i].z;
	t = v[0];
	v[0] = t * cos(data->angle_y) + v[2] * sin(data->angle_y);
	v[2] = -t * sin(data->angle_y) + v[2] * cos(data->angle_y);
	t = v[1];
	v[1] = t * cos(data->angle_x) - v[2] * sin(data->angle_x);
	v[2] = t * sin(data->angle_x) + v[2] * cos(data->angle_x);
	t = v[0];
	v[0] = t * cos(FDF_ISO_Z) - v[1] * sin(FDF_ISO_Z);
	v[1] = t * sin(FDF_ISO_Z) + v[1] * cos(FDF_ISO_Z);
	t = v[1];
	v[1] = t * cos(FDF_ISO_X) - v[2] * sin(FDF_ISO_X);
	v[2] = t * sin(FDF_ISO_X) + v[2] * cos(FDF_ISO_X);
	data->tredi[i].x = v[0] * data->scale + data->off_x;
	data->tredi[i].y = v[1] * data->scale + data->off_y;
	data->tredi[i].z = v[2];
}

void	ft_rebuild_view(t_data *data)
{
	unsigned int	i;
	double			cx;
	double			cy;

	cx = ((double)data->c - 1.0) / 2.0;
	cy = ((double)data->r - 1.0) / 2.0;
	i = 0;
	while (i < data->size)
	{
		ft_project_one(data, i, cx, cy);
		i++;
	}
}

void	ft_redraw(t_data *data)
{
	ft_clear_img(data);
	ft_placelines(data);
	ft_put_img(data);
	if (data->cmd_mode)
		ft_draw_hud(data);
}

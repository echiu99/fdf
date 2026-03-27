/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concoords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:00:13 by echiu             #+#    #+#             */
/*   Updated: 2024/04/23 00:59:26 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_concoords(t_data *data)
{
	int	count;

	count = 0;
	while (count < (int) data->size)
	{
		data->tredi[count].x = (int)(data->tredi[count].x
				* data->scale + (data->w / 2));
		data->tredi[count].y = (int)(data->tredi[count].y
				* data->scale + (data->h / 12));
		count++;
	}
}

void	ft_real_coords(t_data *data)
{
	double	tmp;
	double	tmp2;
	double	tmp3;
	int		count;

	count = 0;
	data->tredi = (t_coords *)malloc(sizeof(t_coords) * (data->size));
	while (count < (int) data->size)
	{
		tmp = data->todi[count].x;
		tmp2 = data->todi[count].y;
		tmp3 = data->todi[count].z;
		data->todi[count].x = tmp * cos(0.78539816339)
			- tmp2 * sin(0.78539816339);
		data->todi[count].y = tmp * sin(0.78539816339)
			+ tmp2 * cos(0.78539816339);
		data->todi[count].z = tmp3 * 1;
		data->tredi[count].x = data->todi[count].x * 1;
		data->tredi[count].y = (data->todi[count].y * cos(0.6154)
				- data->todi[count].z * sin(0.6154));
		data->tredi[count].z = (data->todi[count].y * sin(0.6154)
				+ data->todi[count].z * cos(0.6154));
		count++;
	}
	return ;
}

/*
 * Scale screen-space coords about (mx, my). factor > 1 zooms in, < 1 zooms out.
 * Same math as the old scale_up/scale_down when (mx,my) is window center.
 */
void	ft_zoom_at(t_data *data, int mx, int my, double factor)
{
	int	count;

	count = 0;
	while (count < (int)data->size)
	{
		data->tredi[count].x = mx + (data->tredi[count].x - (double)mx) * factor;
		data->tredi[count].y = my + (data->tredi[count].y - (double)my) * factor;
		count++;
	}
	ft_clear_img(data);
	ft_placelines(data);
#ifndef __APPLE__
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
#endif
}

void	scale_down(t_data *data)
{
	ft_zoom_at(data, data->w / 2, data->h / 2, 0.5);
}

void	scale_up(t_data *data)
{
	ft_zoom_at(data, data->w / 2, data->h / 2, 2.0);
}

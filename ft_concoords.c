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

void	scale_down(t_data *data)
{
	int	x;
	int	y;
	int	count;

	y = -1;
	count = 0;
	while (count < (int) data->size)
	{
		data->tredi[count].x /= 2;
		data->tredi[count].x += ((data->w / 2) / 2);
		data->tredi[count].y /= 2;
		data->tredi[count].y += ((data->h / 2) / 2);
		count++;
	}
	while (y++ < data->h)
	{
		x = -1;
		while (x++ < data->w)
			put_pixel_img(data, x, y, 0x00000000);
	}
	ft_placelines(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return ;
}

void	scale_up(t_data *data)
{
	int	x;
	int	y;
	int	count;

	y = -1;
	count = 0;
	while (count < (int)data->size)
	{
		data->tredi[count].x *= 2;
		data->tredi[count].x -= (data->w / 2);
		data->tredi[count].y *= 2;
		data->tredi[count].y -= (data->h / 2);
		count++;
	}
	while (y++ < data->h)
	{
		x = -1;
		while (x++ < data->w)
			put_pixel_img(data, x, y, 0x00000000);
	}
	ft_placelines(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 01:36:07 by echiu             #+#    #+#             */
/*   Updated: 2024/04/23 01:59:03 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_left(t_data *data)
{
	int	count;

	ft_clear_img(data);
	count = 0;
	while (count < (int)data->size)
	{
		data->tredi[count].x -= 5;
		count++;
	}
	ft_placelines(data);
#ifndef __APPLE__
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
#endif
	return ;
}

void	translate_right(t_data *data)
{
	int	count;

	ft_clear_img(data);
	count = 0;
	while (count < (int)data->size)
	{
		data->tredi[count].x += 5;
		count++;
	}
	ft_placelines(data);
#ifndef __APPLE__
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
#endif
	return ;
}

void	translate_up(t_data *data)
{
	int	count;

	ft_clear_img(data);
	count = 0;
	while (count < (int)data->size)
	{
		data->tredi[count].y -= 5;
		count++;
	}
	ft_placelines(data);
#ifndef __APPLE__
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
#endif
	return ;
}

void	translate_down(t_data *data)
{
	int	count;

	ft_clear_img(data);
	count = 0;
	while (count < (int)data->size)
	{
		data->tredi[count].y += 5;
		count++;
	}
	ft_placelines(data);
#ifndef __APPLE__
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
#endif
	return ;
}

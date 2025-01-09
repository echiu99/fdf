/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 01:05:14 by echiu             #+#    #+#             */
/*   Updated: 2024/04/24 16:02:49 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_img(t_data *data, int x, int y, int color)
{
	char	*dest;

	if (x >= 0 && y >= 0 && x <= data->w && y < data->h)
	{
		dest = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int *) dest = color;
	}
}

void	put_line_high(t_data *data, int i, int j)
{
	int	tmp;

	data->dx = data->tredi[j].x - data->tredi[i].x;
	data->dy = data->tredi[j].y - data->tredi[i].y;
	tmp = 1;
	if (data->dx < 0)
	{
		tmp = -1;
		data->dx = -data->dx;
	}
	data->d = (2 * data->dx) - data->dy;
	data->x = data->tredi[i].x;
	data->y = data->tredi[i].y;
	while (data->y <= data->tredi[j].y)
	{
		put_pixel_img(data, data->x, data->y, data->color);
		if (data->d > 0)
		{
			data->x += tmp;
			data->d = data->d + (2 * (data->dx - data->dy));
		}
		else
			data->d = data->d + 2 * data->dx;
		data->y++;
	}
}

void	put_line_low(t_data *data, int i, int j)
{
	int	tmp;

	data->dx = data->tredi[j].x - data->tredi[i].x;
	data->dy = data->tredi[j].y - data->tredi[i].y;
	tmp = 1;
	if (data->dy < 0)
	{
		tmp = -1;
		data->dy = -data->dy;
	}
	data->d = (2 * data->dy) - data->dx;
	data->y = data->tredi[i].y;
	data->x = data->tredi[i].x;
	while (data->x <= data->tredi[j].x)
	{
		put_pixel_img(data, data->x, data->y, data->color);
		if (data->d > 0)
		{
			data->y += tmp;
			data->d = data->d + (2 * (data->dy - data->dx));
		}
		else
			data->d = data->d + 2 * data->dy;
		data->x++;
	}
}

void	ft_putline(t_data *data, int i, int j)
{
	int	tmp;

	tmp = 0;
	data->dx = ft_abs(data->tredi[j].x - data->tredi[i].x);
	data->dy = ft_abs(data->tredi[j].y - data->tredi[i].y);
	data->low = data->dy < data->dx;
	data->xhigh = data->tredi[i].x > data->tredi[j].x;
	data->yhigh = data->tredi[i].y > data->tredi[j].y;
	if (data->low)
	{
		tmp = data->xhigh;
		if (tmp)
			put_line_low(data, j, i);
		else
			put_line_low(data, i, j);
	}
	else
	{
		tmp = data->yhigh;
		if (tmp)
			put_line_high(data, j, i);
		else
			put_line_high(data, i, j);
	}
}

void	ft_placelines(t_data *data)
{
	data->i = 0;
	data->j = 1;
	data->k = 0;
	data->l = 1;
	data->m = data->c;
	while (data->k < data->r)
	{
		while ((data->i < data->c * data->l) && (data->j != data->c * data->l))
		{
			ft_putline(data, data->i, data->j);
			if (data->l != data->r)
				ft_putline(data, data->i, data->m);
			data->i++;
			data->j++;
			data->m++;
		}
		if ((data->i < data->c * data->l) && (data->j == data->c * data->l)
			&& (data->l != data->r))
			ft_putline(data, data->i, data->m);
		data->i++;
		data->j++;
		data->k++;
		data->l++;
		data->m++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placelines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:10:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 17:10:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

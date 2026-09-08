/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scheme.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:00:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 18:00:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_scheme_apply(t_data *data, int id)
{
	static const int	t[FDF_SCHEME_COUNT][6] = {
	{0x6B, 0x2D, 0x9E, 0x1E, 0x90, 0xFF},
	{0xE8, 0xE8, 0xE8, 0xE8, 0xE8, 0xE8},
	{0x00, 0xC8, 0x6A, 0x00, 0x90, 0xFF},
	{0xFF, 0x3B, 0x1F, 0xFF, 0xD1, 0x00},
	{0x2A, 0x2A, 0x2A, 0xF0, 0xF0, 0xF0},
	};

	id %= FDF_SCHEME_COUNT;
	if (id < 0)
		id += FDF_SCHEME_COUNT;
	data->color_scheme = id;
	data->grad_r0 = t[id][0];
	data->grad_g0 = t[id][1];
	data->grad_b0 = t[id][2];
	data->grad_r1 = t[id][3];
	data->grad_g1 = t[id][4];
	data->grad_b1 = t[id][5];
}

void	ft_scheme_cycle(t_data *data)
{
	ft_scheme_apply(data, data->color_scheme + 1);
	ft_redraw(data);
}

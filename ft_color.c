/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:10:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 17:10:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_color_height(t_data *data, double z)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (z - data->z_min) / (data->z_max - data->z_min);
	if (t < 0.0)
		t = 0.0;
	if (t > 1.0)
		t = 1.0;
	r = (int)(FDF_GRAD_R0 + t * (FDF_GRAD_R1 - FDF_GRAD_R0));
	g = (int)(FDF_GRAD_G0 + t * (FDF_GRAD_G1 - FDF_GRAD_G0));
	b = (int)(FDF_GRAD_B0 + t * (FDF_GRAD_B1 - FDF_GRAD_B0));
	return (fdf_pack_rgb(r, g, b));
}

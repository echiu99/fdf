/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:20:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 17:20:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_plot_aa(t_data *data, t_plot *p)
{
	if (p->steep)
		put_pixel_img(data, p->y, p->x,
			fdf_scale_color(p->color, p->bright));
	else
		put_pixel_img(data, p->x, p->y,
			fdf_scale_color(p->color, p->bright));
}

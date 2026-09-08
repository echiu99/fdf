/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wu_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:10:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 17:20:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	wu_prepare(t_data *data, t_wu *w, int i, int j)
{
	w->x0 = data->tredi[i].x;
	w->y0 = data->tredi[i].y;
	w->x1 = data->tredi[j].x;
	w->y1 = data->tredi[j].y;
	w->z0 = data->todi[i].z;
	w->z1 = data->todi[j].z;
	w->steep = (ft_abs((int)(w->y1 - w->y0)) > ft_abs((int)(w->x1 - w->x0)));
	if (w->steep)
	{
		ft_wu_swap(&w->x0, &w->y0);
		ft_wu_swap(&w->x1, &w->y1);
	}
	if (w->x0 > w->x1)
	{
		ft_wu_swap(&w->x0, &w->x1);
		ft_wu_swap(&w->y0, &w->y1);
		ft_wu_swap(&w->z0, &w->z1);
	}
	w->gradient = 0.0;
	if (w->x1 != w->x0)
		w->gradient = (w->y1 - w->y0) / (w->x1 - w->x0);
}

static void	wu_end_vals(t_wu *w, int px, double *yend, double *xgap)
{
	double	xend;

	if (px == w->xpxl1)
	{
		xend = ft_wu_round(w->x0);
		*yend = w->y0 + w->gradient * (xend - w->x0);
		*xgap = ft_wu_rfpart(w->x0 + 0.5);
		w->intery = *yend + w->gradient;
	}
	else
	{
		xend = ft_wu_round(w->x1);
		*yend = w->y1 + w->gradient * (xend - w->x1);
		*xgap = ft_wu_fpart(w->x1 + 0.5);
	}
}

static void	wu_pair(t_data *data, t_wu *w, t_plot *p, int px)
{
	double	t;
	double	yend;
	double	xgap;

	wu_end_vals(w, px, &yend, &xgap);
	if (w->x1 == w->x0)
		t = 0.5;
	else
		t = ((double)px - w->x0) / (w->x1 - w->x0);
	p->color = fdf_color_height(data, w->z0 + (w->z1 - w->z0) * t);
	p->x = px;
	p->y = ft_wu_ipart(yend);
	p->bright = ft_wu_rfpart(yend) * xgap;
	fdf_plot_aa(data, p);
	p->y = ft_wu_ipart(yend) + 1;
	p->bright = ft_wu_fpart(yend) * xgap;
	fdf_plot_aa(data, p);
}

static void	wu_span(t_data *data, t_wu *w)
{
	t_plot	p;
	double	t;

	p.steep = w->steep;
	p.x = w->xpxl1 + 1;
	while (p.x < w->xpxl2)
	{
		if (w->x1 == w->x0)
			t = 0.5;
		else
			t = ((double)p.x - w->x0) / (w->x1 - w->x0);
		p.color = fdf_color_height(data, w->z0 + (w->z1 - w->z0) * t);
		p.y = ft_wu_ipart(w->intery);
		p.bright = ft_wu_rfpart(w->intery);
		fdf_plot_aa(data, &p);
		p.y = ft_wu_ipart(w->intery) + 1;
		p.bright = ft_wu_fpart(w->intery);
		fdf_plot_aa(data, &p);
		w->intery += w->gradient;
		p.x++;
	}
}

void	ft_putline(t_data *data, int i, int j)
{
	t_wu	w;
	t_plot	p;

	wu_prepare(data, &w, i, j);
	w.xpxl1 = (int)ft_wu_round(w.x0);
	w.xpxl2 = (int)ft_wu_round(w.x1);
	p.steep = w.steep;
	wu_pair(data, &w, &p, w.xpxl1);
	wu_pair(data, &w, &p, w.xpxl2);
	wu_span(data, &w);
}

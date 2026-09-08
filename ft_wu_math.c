/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wu_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:05:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 17:05:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_wu_ipart(double x)
{
	return ((int)floor(x));
}

double	ft_wu_round(double x)
{
	return (floor(x + 0.5));
}

double	ft_wu_fpart(double x)
{
	return (x - floor(x));
}

double	ft_wu_rfpart(double x)
{
	return (1.0 - ft_wu_fpart(x));
}

void	ft_wu_swap(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

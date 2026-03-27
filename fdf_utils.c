/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:28:18 by echiu             #+#    #+#             */
/*   Updated: 2024/04/23 01:09:34 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_compute_z_range(t_data *data)
{
	unsigned int	i;
	double			zmin;
	double			zmax;

	zmin = data->todi[0].z;
	zmax = data->todi[0].z;
	i = 1;
	while (i < data->size)
	{
		if (data->todi[i].z < zmin)
			zmin = data->todi[i].z;
		if (data->todi[i].z > zmax)
			zmax = data->todi[i].z;
		i++;
	}
	if (zmax == zmin)
		zmax = zmin + 1.0;
	data->z_min = zmin;
	data->z_max = zmax;
}

int	ft_strslen(char **map_lines)
{
	int	i;

	i = 0;
	while (map_lines[i])
		i++;
	return (i);
}

void	ft_free_char2(char **tofree)
{
	int	i;

	i = 0;
	while (tofree[i])
		free(tofree[i++]);
	free(tofree);
	return ;
}

void	ft_free_char3(char ***tofree)
{
	int	i;

	i = 0;
	while (tofree[i])
		ft_free_char2(tofree[i++]);
	free(tofree);
	return ;
}

int	ft_abs(int x)
{
	if (x < 0)
		x *= -1;
	return (x);
}

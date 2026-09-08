/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:44:21 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 18:00:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_rows(char ***map_vals, int cols)
{
	int	i;
	int	row_len;

	i = 0;
	while (map_vals[i])
	{
		row_len = 0;
		while (map_vals[i][row_len])
			row_len++;
		if (row_len != cols)
			return (-1);
		i++;
	}
	return (0);
}

static int	char_arr_len(char ***map_vals, unsigned int *out)
{
	int	i;
	int	j;

	if (!map_vals || !map_vals[0] || !map_vals[0][0])
		return (-1);
	i = 0;
	j = 0;
	while (map_vals[i])
		i++;
	while (map_vals[0][j])
		j++;
	if (j <= 0 || check_rows(map_vals, j) < 0)
		return (-1);
	out[0] = (unsigned int)(i * j);
	out[1] = (unsigned int)i;
	out[2] = (unsigned int)j;
	return (0);
}

static int	ft_store_points(char ***map_vals, t_coords *pts)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;

	count = 0;
	i = 0;
	while (map_vals[i])
	{
		j = 0;
		while (map_vals[i][j])
		{
			if (!ft_valid_token(map_vals[i][j]))
				return (-1);
			pts[count].x = (double)j;
			pts[count].y = (double)i;
			pts[count].z = (double)ft_atoi(map_vals[i][j]);
			j++;
			count++;
		}
		i++;
	}
	return (0);
}

static int	ft_fill_coords(char ***map_vals, t_data *data)
{
	unsigned int	out[3];
	t_coords		*pts;

	if (char_arr_len(map_vals, out) < 0)
	{
		ft_free_char3(map_vals);
		return (-1);
	}
	pts = (t_coords *)malloc(sizeof(t_coords) * out[0]);
	if (!pts || ft_store_points(map_vals, pts) < 0)
	{
		free(pts);
		ft_free_char3(map_vals);
		return (-1);
	}
	ft_free_char3(map_vals);
	data->todi = pts;
	data->size = out[0];
	data->r = out[1];
	data->c = out[2];
	return (0);
}

int	ft_load_map_coords(t_data *data, char *map_path)
{
	int		map_fd;
	char	**map_lines;
	char	***map_vals;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd < 0)
		return (-1);
	map_lines = ft_get_map_lines(map_fd);
	close(map_fd);
	if (!map_lines)
		return (-1);
	map_vals = ft_mapline_tostr(map_lines);
	if (!map_vals)
		return (-1);
	return (ft_fill_coords(map_vals, data));
}

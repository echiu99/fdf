/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:44:21 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 17:25:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	check_rows(char ***map_vals, t_data *data, int cols)
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
			ft_fail_map(data, map_vals, "Invalid map: non-rectangular rows");
		i++;
	}
}

static void	char_arr_len(char ***map_vals, t_data *data)
{
	int	i;
	int	j;

	if (!map_vals || !map_vals[0] || !map_vals[0][0])
		ft_fail_map(data, map_vals, "Invalid map: empty or malformed");
	i = 0;
	j = 0;
	while (map_vals[i])
		i++;
	while (map_vals[0][j])
		j++;
	if (j <= 0)
		ft_fail_map(data, map_vals, "Invalid map: empty first row");
	check_rows(map_vals, data, j);
	data->size = i * j;
	data->r = i;
	data->c = j;
}

void	ft_get_coords(char ***map_vals, t_data *data)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;

	char_arr_len(map_vals, data);
	count = 0;
	data->todi = (t_coords *)malloc(sizeof(t_coords) * (data->size));
	i = 0;
	while (map_vals[i])
	{
		j = 0;
		while (map_vals[i][j])
		{
			if (!ft_valid_token(map_vals[i][j]))
				ft_fail_map(data, map_vals, "Invalid map: bad height token");
			data->todi[count].x = (double)j;
			data->todi[count].y = (double)i;
			data->todi[count].z = (double)ft_atoi(map_vals[i][j]);
			j++;
			count++;
		}
		i++;
	}
	ft_free_char3(map_vals);
}

void	ft_get_map(char *map_path, t_data *data)
{
	int		map_fd;
	char	**map_lines;
	char	***map_vals;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd < 0)
	{
		perror("Error opening file\n");
		if (errno == ENOENT)
			ft_printf("File does not exist:%s\n", map_path);
		else if (errno == EACCES)
			ft_printf("Change access permissions for file: %s\n", map_path);
		close_win(data, 1);
		exit(EXIT_FAILURE);
	}
	map_lines = ft_get_map_lines(map_fd);
	close(map_fd);
	if (!map_lines)
		ft_fail_map(data, NULL, "Invalid map: empty file or read failure");
	map_vals = ft_mapline_tostr(map_lines);
	if (!map_vals)
		ft_fail_map(data, NULL, "Invalid map: allocation failure");
	ft_get_coords(map_vals, data);
}

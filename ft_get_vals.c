/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:44:21 by echiu             #+#    #+#             */
/*   Updated: 2024/04/24 16:11:46 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_get_map_lines(int map_fd)
{
	char	*gnl_ret;
	char	*str;
	char	*tofree;
	char	**map_lines;

	gnl_ret = get_next_line(map_fd);
	if (!gnl_ret)
		return (NULL);
	str = ft_strdup("");
	if (!str)
		return (NULL);
	while (gnl_ret)
	{
		tofree = str;
		str = ft_strjoin(str, gnl_ret);
		if (!str)
			return (free(gnl_ret), free(tofree), NULL);
		free(tofree);
		gnl_ret = (free(gnl_ret), get_next_line(map_fd));
	}
	map_lines = ft_split(str, '\n');
	if (!map_lines)
		return (free(str), NULL);
	return (free(str), map_lines);
}

char	***ft_mapline_tostr(char **map_lines)
{
	size_t	i;
	char	***map_str_vals;

	map_str_vals = (char ***)ft_calloc((ft_strslen(map_lines)
				+ 1), sizeof(char **));
	if (!map_str_vals)
		return (ft_free_char2(map_lines), NULL);
	i = 0;
	while (map_lines[i])
	{
		map_str_vals[i] = ft_split(map_lines[i], ' ');
		if (!map_str_vals[i])
			return (ft_free_char3(map_str_vals),
				ft_free_char2(map_lines), NULL);
		i++;
	}
	return (ft_free_char2(map_lines), map_str_vals);
}

void	char_arr_len(char ***map_vals, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_vals[i])
		i++;
	while (map_vals[0][j])
		j++;
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
	int	map_fd;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd < 0)
	{
		perror("Error opening file\n");
		if (errno == ENOENT)
			ft_printf("File does not exist:%s\n", map_path);
		else if (errno == EACCES)
			ft_printf("Change access permissions for file: %s\n", map_path);
		close_win(data, 1);
		exit (EXIT_FAILURE);
	}
	ft_get_coords(ft_mapline_tostr(ft_get_map_lines(map_fd)), data);
}

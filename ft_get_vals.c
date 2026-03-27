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

static void	fail_map_parse(t_data *data, char ***map_vals, char *msg)
{
	if (map_vals)
		ft_free_char3(map_vals);
	ft_printf("%s\n", msg);
	close_win(data, 1);
}

static int	is_hex_char(char c)
{
	return ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F'));
}

static int	is_valid_height_token(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (!str[i])
		return (1);
	if (str[i] != ',')
		return (0);
	i++;
	if (!(str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X')))
		return (0);
	i += 2;
	if (!is_hex_char(str[i]))
		return (0);
	while (is_hex_char(str[i]))
		i++;
	return (str[i] == '\0');
}

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
	int	row_len;

	if (!map_vals || !map_vals[0] || !map_vals[0][0])
		fail_map_parse(data, map_vals, "Invalid map: empty or malformed");
	i = 0;
	j = 0;
	while (map_vals[i])
		i++;
	while (map_vals[0][j])
		j++;
	if (j <= 0)
		fail_map_parse(data, map_vals, "Invalid map: empty first row");
	i = 0;
	while (map_vals[i])
	{
		row_len = 0;
		while (map_vals[i][row_len])
			row_len++;
		if (row_len != j)
			fail_map_parse(data, map_vals, "Invalid map: non-rectangular rows");
		i++;
	}
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
			if (!is_valid_height_token(map_vals[i][j]))
				fail_map_parse(data, map_vals, "Invalid map: bad height token");
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
		exit (EXIT_FAILURE);
	}
	map_lines = ft_get_map_lines(map_fd);
	close(map_fd);
	if (!map_lines)
		fail_map_parse(data, NULL, "Invalid map: empty file or read failure");
	map_vals = ft_mapline_tostr(map_lines);
	if (!map_vals)
		fail_map_parse(data, NULL, "Invalid map: allocation failure");
	ft_get_coords(map_vals, data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:25:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 17:25:00 by echiu            ###   ########.fr       */
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
		free(gnl_ret);
		gnl_ret = get_next_line(map_fd);
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

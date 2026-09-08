/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:00:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 18:00:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <dirent.h>

void	ft_maps_free(t_data *data)
{
	int	i;

	if (!data->map_names)
		return ;
	i = 0;
	while (i < data->map_count)
	{
		free(data->map_names[i]);
		i++;
	}
	free(data->map_names);
	data->map_names = NULL;
	data->map_count = 0;
}

void	ft_free_runtime(t_data *data)
{
	ft_hud_clear(data);
	ft_maps_free(data);
	free(data->map_path);
	data->map_path = NULL;
	free(data->todi);
	free(data->tredi);
	data->todi = NULL;
	data->tredi = NULL;
}

static int	ft_is_fdf_name(char *name)
{
	size_t	n;

	if (!name || name[0] == '.')
		return (0);
	n = ft_strlen(name);
	if (n < 5)
		return (0);
	return (ft_strncmp(name + n - 4, ".fdf", 4) == 0);
}

static int	ft_collect_maps(DIR *dir, char **names)
{
	struct dirent	*ent;
	int				n;

	n = 0;
	ent = readdir(dir);
	while (ent && n < FDF_MAX_MAPS)
	{
		if (ft_is_fdf_name(ent->d_name))
		{
			names[n] = ft_strdup(ent->d_name);
			if (!names[n])
				break ;
			n++;
		}
		ent = readdir(dir);
	}
	return (n);
}

void	ft_maps_scan(t_data *data)
{
	DIR		*dir;
	char	**names;

	data->map_names = NULL;
	data->map_count = 0;
	dir = opendir("maps");
	if (!dir)
		return ;
	names = (char **)malloc(sizeof(char *) * FDF_MAX_MAPS);
	if (!names)
	{
		closedir(dir);
		return ;
	}
	data->map_count = ft_collect_maps(dir, names);
	closedir(dir);
	data->map_names = names;
}

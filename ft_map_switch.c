/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_switch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:00:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 18:00:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_has_fdf_suffix(char *s)
{
	size_t	n;

	n = ft_strlen(s);
	if (n < 4)
		return (0);
	return (ft_strncmp(s + n - 4, ".fdf", 4) == 0);
}

char	*ft_resolve_map_arg(char *arg)
{
	char	*tmp;
	char	*path;
	int		i;

	if (!arg || !arg[0])
		return (NULL);
	i = 0;
	while (arg[i] && arg[i] != '/')
		i++;
	if (arg[i] == '/')
		return (ft_strdup(arg));
	if (ft_has_fdf_suffix(arg))
		return (ft_strjoin(FDF_MAPS_DIR, arg));
	tmp = ft_strjoin(arg, ".fdf");
	if (!tmp)
		return (NULL);
	path = ft_strjoin(FDF_MAPS_DIR, tmp);
	free(tmp);
	return (path);
}

static void	ft_apply_new_map(t_data *data, char *new_path)
{
	free(data->map_path);
	data->map_path = new_path;
	ft_compute_z_range(data);
	ft_alloc_view(data);
	data->angle_x = 0.0;
	data->angle_y = 0.0;
	data->scale = FDF_DEFAULT_SCALE;
	data->off_x = (double)data->w / 2.0;
	data->off_y = (double)data->h / 4.0;
	ft_rebuild_view(data);
}

static void	ft_restore_old(t_data *data, t_coords *todi, t_coords *tredi,
		unsigned int size)
{
	data->todi = todi;
	data->tredi = tredi;
	data->size = size;
}

int	ft_switch_map(t_data *data, char *path)
{
	t_coords		*old_todi;
	t_coords		*old_tredi;
	unsigned int	old_size;
	char			*new_path;

	old_todi = data->todi;
	old_tredi = data->tredi;
	old_size = data->size;
	data->todi = NULL;
	data->tredi = NULL;
	if (ft_load_map_coords(data, path) < 0)
		return (ft_restore_old(data, old_todi, old_tredi, old_size), -1);
	new_path = ft_strdup(path);
	if (!new_path)
	{
		free(data->todi);
		return (ft_restore_old(data, old_todi, old_tredi, old_size), -1);
	}
	free(old_todi);
	free(old_tredi);
	ft_apply_new_map(data, new_path);
	return (0);
}

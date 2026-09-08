/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:00:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 18:00:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_cmd_arg(char *buf)
{
	if (!buf[0])
		return (NULL);
	if (buf[0] == 'e' && buf[1] == '\0')
		return (buf);
	if (buf[0] == 'e' && buf[1] == ' ')
		return (buf + 2);
	return (buf);
}

void	ft_cmd_exec(t_data *data)
{
	char	*arg;
	char	*path;

	arg = ft_cmd_arg(data->cmd_buf);
	if (!arg)
		return (ft_cmd_cancel(data));
	if (arg[0] == 'e' && arg[1] == '\0')
		path = ft_strdup(data->map_path);
	else
		path = ft_resolve_map_arg(arg);
	data->cmd_mode = 0;
	data->cmd_len = 0;
	data->cmd_buf[0] = '\0';
	ft_hud_clear(data);
	if (!path || ft_switch_map(data, path) < 0)
		ft_printf("Map load failed: %s\n", arg);
	else
		ft_redraw(data);
	free(path);
}

static void	ft_set_cmd_match(t_data *data, char *match)
{
	char	*start;
	int		keep;

	start = data->cmd_buf;
	if (data->cmd_buf[0] == 'e' && data->cmd_buf[1] == ' ')
		start = data->cmd_buf + 2;
	keep = (int)(start - data->cmd_buf);
	if (keep + (int)ft_strlen(match) >= FDF_CMD_MAX)
		return ;
	ft_strlcpy(start, match, FDF_CMD_MAX - keep);
	data->cmd_len = (int)ft_strlen(data->cmd_buf);
	ft_draw_hud(data);
}

static void	ft_list_matches(t_data *data, char *prefix)
{
	int	i;

	i = 0;
	while (i < data->map_count)
	{
		if (ft_strncmp(data->map_names[i], prefix, ft_strlen(prefix)) == 0)
			ft_printf("%s\n", data->map_names[i]);
		i++;
	}
}

void	ft_cmd_complete(t_data *data)
{
	char	*prefix;
	char	*match;
	int		i;
	int		hits;

	prefix = data->cmd_buf;
	if (data->cmd_buf[0] == 'e' && data->cmd_buf[1] == ' ')
		prefix = data->cmd_buf + 2;
	match = NULL;
	hits = 0;
	i = -1;
	while (++i < data->map_count)
	{
		if (ft_strncmp(data->map_names[i], prefix, ft_strlen(prefix)) == 0)
		{
			match = data->map_names[i];
			hits++;
		}
	}
	if (hits == 1)
		ft_set_cmd_match(data, match);
	else if (hits > 1)
		ft_list_matches(data, prefix);
}

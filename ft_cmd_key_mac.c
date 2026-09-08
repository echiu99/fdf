/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_key_mac.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:00:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 18:00:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	ft_cmd_char(int key, int shift)
{
	if (key >= MLX_KEY_A && key <= MLX_KEY_Z)
	{
		if (shift)
			return ((char)key);
		return ((char)(key + 32));
	}
	if (key >= MLX_KEY_0 && key <= MLX_KEY_9)
		return ((char)key);
	if (key == MLX_KEY_PERIOD)
		return ('.');
	if (key == MLX_KEY_MINUS && shift)
		return ('_');
	if (key == MLX_KEY_MINUS)
		return ('-');
	if (key == MLX_KEY_SLASH)
		return ('/');
	if (key == MLX_KEY_SPACE)
		return (' ');
	return (0);
}

int	ft_cmd_key(t_data *data, int key, int shift)
{
	char	c;

	if (key == MLX_KEY_ESCAPE)
		return (ft_cmd_cancel(data), 0);
	if (key == MLX_KEY_ENTER)
		return (ft_cmd_exec(data), 0);
	if (key == MLX_KEY_BACKSPACE)
		return (ft_cmd_backspace(data), 0);
	if (key == MLX_KEY_TAB)
		return (ft_cmd_complete(data), 0);
	c = ft_cmd_char(key, shift);
	if (c)
		ft_cmd_append(data, c);
	return (0);
}

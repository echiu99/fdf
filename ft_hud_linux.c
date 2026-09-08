/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud_linux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:00:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 18:00:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_hud_clear(t_data *data)
{
	(void)data;
}

void	ft_draw_hud(t_data *data)
{
	char	line[FDF_CMD_MAX + 2];

	if (!data->cmd_mode)
		return ;
	line[0] = ':';
	ft_strlcpy(line + 1, data->cmd_buf, FDF_CMD_MAX + 1);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 12, data->h - 20,
		0x00FFFFFF, line);
}

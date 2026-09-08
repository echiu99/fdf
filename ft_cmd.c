/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:00:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 18:00:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_cmd_open(t_data *data)
{
	data->cmd_mode = 1;
	data->cmd_len = 0;
	data->cmd_buf[0] = '\0';
	ft_draw_hud(data);
}

void	ft_cmd_cancel(t_data *data)
{
	data->cmd_mode = 0;
	data->cmd_len = 0;
	data->cmd_buf[0] = '\0';
	ft_hud_clear(data);
	ft_redraw(data);
}

void	ft_cmd_append(t_data *data, char c)
{
	if (data->cmd_len >= FDF_CMD_MAX - 1)
		return ;
	data->cmd_buf[data->cmd_len] = c;
	data->cmd_len++;
	data->cmd_buf[data->cmd_len] = '\0';
	ft_draw_hud(data);
}

void	ft_cmd_backspace(t_data *data)
{
	if (data->cmd_len <= 0)
		return ;
	data->cmd_len--;
	data->cmd_buf[data->cmd_len] = '\0';
	ft_draw_hud(data);
}

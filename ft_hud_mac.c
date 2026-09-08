/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud_mac.c                                       :+:      :+:    :+:   */
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
	if (data->hud_img)
	{
		mlx_delete_image((mlx_t *)data->mlx_ptr, (mlx_image_t *)data->hud_img);
		data->hud_img = NULL;
	}
}

void	ft_draw_hud(t_data *data)
{
	char	line[FDF_CMD_MAX + 2];

	ft_hud_clear(data);
	if (!data->cmd_mode)
		return ;
	line[0] = ':';
	ft_strlcpy(line + 1, data->cmd_buf, FDF_CMD_MAX + 1);
	data->hud_img = mlx_put_string((mlx_t *)data->mlx_ptr, line, 12,
			data->h - 36);
}

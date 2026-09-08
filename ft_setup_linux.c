/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_linux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:55:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 16:55:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_setup_hooks(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_hook(data->win_ptr, 17, 0, close_event, data);
	mlx_key_hook(data->win_ptr, read_keys, data);
	mlx_mouse_hook(data->win_ptr, mouse_hook_linux, data);
}

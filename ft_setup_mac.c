/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_mac.c                                     :+:      :+:    :+:   */
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
	mlx_key_hook((mlx_t *)data->mlx_ptr, read_keys_mac, data);
	mlx_close_hook((mlx_t *)data->mlx_ptr, close_event_mac, data);
	mlx_scroll_hook((mlx_t *)data->mlx_ptr, scroll_hook_mac, data);
}

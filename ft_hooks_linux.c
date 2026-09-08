/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_linux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:50:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 16:50:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_hook_linux(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->cmd_mode)
		return (0);
	if (button == 4)
		ft_zoom_at(data, x, y, FDF_ZOOM_WHEEL);
	else if (button == 5)
		ft_zoom_at(data, x, y, 1.0 / FDF_ZOOM_WHEEL);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_key_linux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:00:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 18:00:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_cmd_key(t_data *data, int key, int shift)
{
	(void)shift;
	if (key == XK_Escape)
		return (ft_cmd_cancel(data), 0);
	if (key == XK_Return)
		return (ft_cmd_exec(data), 0);
	if (key == XK_BackSpace)
		return (ft_cmd_backspace(data), 0);
	if (key == XK_Tab)
		return (ft_cmd_complete(data), 0);
	if (key >= 32 && key <= 126)
		ft_cmd_append(data, (char)key);
	return (0);
}

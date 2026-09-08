/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:25:00 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 17:25:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fail_map(t_data *data, char ***map_vals, char *msg)
{
	if (map_vals)
		ft_free_char3(map_vals);
	ft_printf("%s\n", msg);
	close_win(data, 1);
}

static int	is_hex_char(char c)
{
	return ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F'));
}

int	ft_valid_token(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (!str[i])
		return (1);
	if (str[i] != ',')
		return (0);
	i++;
	if (!(str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X')))
		return (0);
	i += 2;
	if (!is_hex_char(str[i]))
		return (0);
	while (is_hex_char(str[i]))
		i++;
	return (str[i] == '\0');
}

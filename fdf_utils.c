/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:28:18 by echiu             #+#    #+#             */
/*   Updated: 2024/04/23 01:09:34 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strslen(char **map_lines)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (map_lines[i])
	{
		len += ft_strlen(map_lines[i]);
		i++;
	}
	return (len);
}

void	ft_free_char2(char **tofree)
{
	int	i;

	i = 0;
	while (tofree[i])
		free(tofree[i++]);
	free(tofree);
	return ;
}

void	ft_free_char3(char ***tofree)
{
	int	i;

	i = 0;
	while (tofree[i])
		ft_free_char2(tofree[i++]);
	free(tofree);
	return ;
}

int	ft_abs(int x)
{
	if (x < 0)
		x *= -1;
	return (x);
}

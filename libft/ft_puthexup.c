/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:39:41 by echiu             #+#    #+#             */
/*   Updated: 2023/11/21 17:08:08 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_hexup(unsigned int n)
{
	if (n >= 16)
	{
		ft_put_hexup(n / 16);
		ft_put_hexup(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + 'A'), 1);
	}
}

int	ft_puthexup(unsigned int str)
{
	int	ret;

	ret = 0;
	if (str == 0)
	{
		ret += ft_putchar('0');
		return (ret);
	}
	ft_put_hexup(str);
	ret += ft_hex_len(str);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:09:40 by echiu             #+#    #+#             */
/*   Updated: 2023/11/21 17:11:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_hexlo(unsigned int n)
{
	if (n >= 16)
	{
		ft_put_hexlo(n / 16);
		ft_put_hexlo(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + 'a'), 1);
	}
}

int	ft_puthexlo(unsigned int str)
{
	int	ret;

	ret = 0;
	if (str == 0)
	{
		ret += ft_putchar('0');
		return (ret);
	}
	ft_put_hexlo(str);
	ret += ft_hex_len(str);
	return (ret);
}

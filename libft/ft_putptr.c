/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:50:19 by echiu             #+#    #+#             */
/*   Updated: 2023/11/21 15:50:59 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexlen(uintptr_t n)
{
	int	i;

	i = 0;
	while (n != '\0')
	{
		i++;
		n = n / 16;
	}
	return (i);
}

void	ft_put_ptr(uintptr_t n)
{
	if (n >= 16)
	{
		ft_put_ptr(n / 16);
		ft_put_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + 'a'), 1);
	}
}

int	ft_putptr(unsigned long long str)
{
	int	ret;

	ret = 0;
	if (str == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ret += write(1, "0x", 2);
	ft_put_ptr(str);
	ret += ft_hexlen(str);
	return (ret);
}

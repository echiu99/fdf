/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conman.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:57:04 by echiu             #+#    #+#             */
/*   Updated: 2023/11/21 17:05:40 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_conman(const char str, va_list ptr)
{
	int	ret;

	ret = 0;
	if (str == 'c')
		ret += ft_putchar(va_arg(ptr, int));
	if (str == 's')
		ret += ft_putstr(va_arg(ptr, char *));
	if (str == 'p')
		ret += ft_putptr(va_arg(ptr, unsigned long long));
	if (str == 'd' || str == 'i')
		ret += ft_putnbr(va_arg(ptr, int));
	if (str == 'u')
		ret += ft_putun_int(va_arg(ptr, unsigned int));
	if (str == 'x')
		ret += ft_puthexlo(va_arg(ptr, unsigned int));
	if (str == 'X')
		ret += ft_puthexup(va_arg(ptr, unsigned int));
	return (ret);
}

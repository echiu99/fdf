/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:30:55 by echiu             #+#    #+#             */
/*   Updated: 2023/11/21 15:33:28 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	va_list	ptr;

	i = 0;
	ret = 0;
	va_start(ptr, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ret += ft_conman(str[i + 1], ptr);
			if (str[i + 1] == '%')
				ret += ft_putchar('%');
			i++;
		}
		else
			ret += ft_putchar(str[i]);
		i++;
	}
	va_end(ptr);
	return (ret);
}

/* int	main(void)
{
	ft_printf(" %x", 0);
	printf("\n %x\n", 0);
	return (0);
} */

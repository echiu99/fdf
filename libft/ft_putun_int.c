/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:01:54 by echiu             #+#    #+#             */
/*   Updated: 2023/11/20 20:30:19 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != '\0')
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_putun_int(unsigned int n)
{
	int		ret;
	char	*num;

	ret = 0;
	if (n == 0)
		ret += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		ret += ft_putstr(num);
		free(num);
	}
	return (ret);
}

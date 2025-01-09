/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:45:14 by echiu             #+#    #+#             */
/*   Updated: 2023/11/03 18:13:37 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	ch;

	i = 0;
	ptr = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (*ptr == ch)
			return (ptr);
		i++;
		ptr++;
	}
	return (NULL);
}

//int	main(void)
//{
//	const char	str[] = "Hello There";
//	int	c = 'o';
//
//	char *ret;
//
//	ret = ft_memchr(str, c, 5);
//
//	printf("|%c|\n|%s|", c, ret);
//
//	return (0);
//}

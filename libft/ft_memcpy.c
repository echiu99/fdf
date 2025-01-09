/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:15:42 by echiu             #+#    #+#             */
/*   Updated: 2023/11/03 17:27:34 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	while (i < n)
	{
		*((char *)str1 + i) = *((char *)str2 + i);
		i++;
	}
	return (str1);
}

//int	main(void)
//{
//	char src[] = "Hello";
//	char dest[6];
//	ft_memcpy(dest, src, 4);
//	puts(dest);
//	return (0);
//}

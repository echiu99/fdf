/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:56:43 by echiu             #+#    #+#             */
/*   Updated: 2023/11/03 17:28:36 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*s;
	char			*d;
	size_t			i;

	s = (char *)src;
	d = (char *)dest;
	i = 0;
	if (d > s)
		while (n-- > 0)
			d[n] = s[n];
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

//int	main(void)
//{
//	char src[] = "Hello There";
//	char dest[] = "Goodbye";
//	ft_memmove(dest, src, 9);
//	puts(dest);
//	return (0);
//}

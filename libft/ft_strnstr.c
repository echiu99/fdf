/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:37:31 by echiu             #+#    #+#             */
/*   Updated: 2023/11/03 14:34:40 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	litlen;
	char	*ptr;

	i = 0;
	litlen = ft_strlen(little);
	ptr = (char *)big;
	if (litlen == 0 || big == little)
		return (ptr);
	while (ptr[i] != '\0' && i < len)
	{
		j = 0;
		while (ptr[i + j] != '\0' && little[j] != '\0'
			&& ptr[i + j] == little[j] && i + j < len)
			j++;
		if (j == litlen)
			return (ptr + i);
		i++;
	}
	return (0);
}

/* int	main(int ac, char **av)
{
	char *big = av[1];
	char *little = av[2];

	if (ac == 3)
	{
		big = ft_strnstr(big, little, 15);		
		printf("%s\n", big);
	}
	return (0);
} */

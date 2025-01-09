/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:52:04 by echiu             #+#    #+#             */
/*   Updated: 2023/11/03 17:38:55 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] < s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/* int	main(void)
{
	long unsigned int	j;
	
	j = 5;
	printf("%d\n", ft_strncmp("HelloHowAreYouDoing", "HelloThereWorld", 5));
	printf("%d\n", strncmp("HelloHowAreYouDoing", "HelloThereWorld", j));
	return (0);
} */

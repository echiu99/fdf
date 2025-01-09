/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:21:23 by echiu             #+#    #+#             */
/*   Updated: 2023/11/03 19:07:22 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		ret = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
		if (ret == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			ret[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			ret[len1] = s2[i];
			len1++;
		}
		ret[len1] = '\0';
		return (ret);
	}
	return (NULL);
}

/* int	main(int argc, char **argv)
{
	char *s1 = argv[1];
	char *s2 = argv[2];
	char *ret;

	if (argc == 3)
	{
		ret = ft_strjoin(s1, s2);
		printf("%s\n", ret);
	}
	return (0);
} */

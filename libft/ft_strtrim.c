/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:25:13 by echiu             #+#    #+#             */
/*   Updated: 2023/11/11 13:56:55 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*ret;
	int		start;
	int		end;

	if (!s1 || !set)
		return ((char *) NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]))
		start++;
	if (start > end)
		return (ft_strdup(s1 + end + 1));
	while (ft_strchr(set, s1[end]) && end >= start)
		end--;
	ret = malloc(end - start + 2);
	if (!ret)
		return ((char *) NULL);
	ft_strlcpy(ret, &s1[start], end - start + 2);
	return (ret);
}

/* int	main()
{
	char * s = ft_strtrim("", "123");
	printf("|%s|\n", s);
	return (0);
} */

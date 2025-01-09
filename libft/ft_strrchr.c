/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:47:24 by echiu             #+#    #+#             */
/*   Updated: 2023/11/09 22:05:09 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	if ((char) c == 0)
		return ((char *)s + ft_strlen(s));
	len = ft_strlen(s) - 1;
	if (len < 0)
		return ((char *) NULL);
	while (s[len] != (char)c && len != 0)
		len--;
	if (s[len] == (char)c)
		return ((char *)&s[len]);
	return ((char *) NULL);
}

//int	main()
//{
//	const char	str[] = "Hello there";
//	const char	ch = 'o';
//
//	char *ret;
//	char *gret;
//
//	ret = ft_strrchr(str, ch);
//	gret = strrchr(str, ch);
//
//	printf("|%c|\n|%s|\n", ch, ret);
//	printf("|%c|\n|%s|\n", ch, gret);
//
//	return (0);
//}

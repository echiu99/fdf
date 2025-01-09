/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:03:57 by echiu             #+#    #+#             */
/*   Updated: 2023/11/11 12:32:03 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (ft_strlen(s) < start)
	{
		len = 0;
		start = 0;
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ret = (char *)malloc(len + 1);
	if (!s || !ret)
		return (NULL);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		ret[j++] = s[i++];
	ret[j] = '\0';
	return (ret);
}

/* int main(void)
{
  char * str = strdup("1");
  char * s = ft_substr(str, 42, 42000000);
  printf("%s\n", s);
  return (0);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:13:06 by echiu             #+#    #+#             */
/*   Updated: 2023/11/07 16:53:42 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* char	my_fun(unsigned int i, char str)
{
	printf("This is a test: index = %d and %c\n", i, str);
	return str;
}

int	main(void)
{
	const char	*s = "Hello There";

	printf("The result is %s\n", s);
	char *result = ft_strmapi(s, my_fun);
	printf("%s\n", result);
	return (0);
} */

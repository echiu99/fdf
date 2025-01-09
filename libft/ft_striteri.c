/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:21:43 by echiu             #+#    #+#             */
/*   Updated: 2023/11/07 19:48:43 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}

/* void	my_fun(unsigned int i, char *str)
{
	printf("This is a test: index = %d and %s\n", i, str);
	return ;
}

int	main(void)
{
	char	*ret = "Hello There";
	
	printf("The result is %s\n", ret);
	ft_striteri(ret, my_fun);
	printf("%s\n", ret);
	return (0);
} */

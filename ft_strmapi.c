/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2024/10/28 13:53:14 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	les parametres de f sont imposes arbitrairement : i et s[i] */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*ret;

	if (s)
	{
		len = ft_strlen(s);
		ret = (char *) malloc((len + 1) * sizeof(char));
		if (!ret)
			return (NULL);
		ret[len] = '\0';
		while (len--)
			ret[len] = f(len, s[len]);
		return (ret);
	}
	return (NULL);
}

/*
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// MAIN
char	f(unsigned int ii, char c)
{
	if (ii % 2)
		return (int) (c);
	else
		return (int) ('-');
}

int	main(void)
{
	char str[] = "abcdef";
	//char (*func)(unsigned int, char);
	printf("%s\n", ft_strmapi(str, &f));
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2022/03/02 18:40:52 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	ii;
	char			*ret;

	ret = (char *) malloc(sizeof(char) * (ft_strlen((char *) s) + 1));
	ii = 0;
	while (s[ii] != '\0')
	{
		ret[ii] = f(ii, s[ii]);
		ii++;
	}
	ret[ii] = '\0';
	return (ret);
}
/*
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// MAIN
int f(int ii, char c)
{
	if (ii % 2)
		return (int) (c);
	else
		return (int) ('-');
}

int	main(int argc, char *argv[])
{
	int ii = 0;
	printf("%s\n", ft_strmapi("abc", f));
	printf("%s\n", ft_strmapi("abc", f));
}
*/

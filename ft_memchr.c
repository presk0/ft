/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2024/10/28 18:43:31 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*mem;
	char	byte;

	mem = (char *)s;
	byte = c;
	if (n)
		while (n--)
			if (*mem++ == byte)
				return (--mem);
	return (NULL);
}

/*
//
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
// MAIN
int test_memchr(char *str, char c)
{
	unsigned int	diff;
	char			*ret;
	int				ii;

	ii = 0;
	while (ii < 5)
	{
		diff = memchr(str, c, ii) - ft_memchr(str, c, ii);
		if (diff)
		{
			printf("[bug] at str: %s, c: %c, n = %d\n", str, c, ii);
			ret = memchr(str, c, ii);
			printf("original: %s\n", ret);
			ret = ft_memchr(str, c, ii);
			printf("mine    : %s\n", ret);
			return (1);
		}
		ii++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int ii = 0;
	test_memchr("abcbi", 'b');
	test_memchr("abc", '\0');
	test_memchr("", 'a');
	test_memchr("", '\0');
	printf("test finished\n");
}
*/

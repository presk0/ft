/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2022/03/08 19:25:15 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	unsigned int	src_len;
	unsigned int	ret;

	src_len = ft_strlen(src);
	ret = src_len;
	while (dstsize-- > 0 && *src)
		*dst++ = *src++;
	if (dstsize =! -1)
		*dst = '\0';
	return (src_len);
}

/*
//
#include <string.h>
#include <stdio.h>
// MAIN
int test_strlcpy(char *to_cpy, int len)
{
	char	*s1;
	char	*s2;
	int		ii = 0;
	int		jj = 0;

	s1 = malloc(sizeof(char) * 20);
	s2 = malloc(sizeof(char) * 20);
	strlcpy(s1, to_cpy, len);
	ft_strlcpy(s2, to_cpy, len);
	printf("originale: [%s]	=>	ft_: [%s]\n",  s1, s2);
	return (strncmp(s1, s2, len));
}

int	main(int argc, char *argv[])
{
	int ii = 0;
	int diff;

	while (ii < 5)
	{
		if (diff = test_strlcpy("abc", ii))
			printf("error at %s, len = %d\n", "abc", ii);
		ii++;
	}

	ii = 0;
	while (ii < 2)
	{
		if (diff = test_strlcpy("", ii))
			printf("error at %s, len = %d\n", "abc", ii);
		ii++;
	}
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2022/03/01 14:15:14 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int	ft_strlcat(char *dst, char *src, unsigned int dstsize)
{
	unsigned int	ii;
	unsigned int	src_len;
	unsigned int	dst_len;
	unsigned int	ret;

	ii = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	ret = src_len + dst_len;
	if (!dstsize)
		return (ret);
	while (ii < dstsize - 1 && src[ii])
	{
		dst[dst_len + ii] = src[ii];
		ii++;
	}
	dst[dst_len + dstsize - 1] = '\0';
	return (ret);
}
/*
//
#include "error_msg.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
// MAIN
int test_strlcat(char *str, char *to_append, int len)
{
	char	*s1;
	char	*s2;
	int		ret;
	int		ii = 0;
	int		jj = 0;

	s1 = malloc(sizeof(char) * (strlen(str) + strlen(to_append) + 2));
	s2 = malloc(sizeof(char) * (strlen(str) + strlen(to_append) + 2));
	strcpy(s1, str);
	strcpy(s2, str);
	strlcat(s1, to_append, len);
	ft_strlcat(s2, to_append, len);
	if ((ret = strncmp(s1, s2, len)))
	{
		printf("Error when len = %d, src = %s, dst = %s\n\
			s1 (   strlcat): [%s]\n\
			s2 (ft_strlcat): [%s]\n\n", len, to_append, str, s1, s2);
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int ii = 0;
	char s_abc[] = "abc";
	char s_empty[] = "";
	int diff;

	while (ii < 5)
	{
		test_strlcat(s_abc, s_empty, ii);
		ii++;
	}
	ii = 0;
	while (ii < 2)
	{
		test_strlcat(s_abc, s_empty, ii);
		ii++;
	}
	printf("can be a good job ;)\n");
}
*/

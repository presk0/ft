/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2022/03/08 19:22:43 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, \
			unsigned int len)
{
	char	*dst_cpy;
	char	*src_cpy;

	dst_cpy = (char *) dst;
	src_cpy = (char *) src;
	while (*dst_cpy && *src_cpy && len--)
	{
		*dst_cpy++ = *src_cpy++;
	}
	return (dst);
}

/*
//
#include "error_msg.h"
#include <ctype.h>
#include <string.h>
// MAIN
int test_memcpy(char *to_cpy, int len)
{
	char	s1[1000];
	char	s2[1000];
	int		ii = 0;

	memcpy(s1, to_cpy);
	ft_memcpy(s2, to_cpy);
	while (ii < len)
	{
		if (s1[ii] != s2[ii])
		{
			printf("differents output for str=[%s]\nmemcpy(str) = [%s]\n\
			ft_memcpy(str) = [%s]\nlen/str_bufsize = %d\nbuf_size = %d\n"\
			, str, s1, s2, len, buf_size);
			printf("\n");
			printf("\n");
			return (1);
		}
		ii++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int ii = 0;

	while (ii < 5)
	{
		char str[ii];
		strcpy(str, "abc\n");
		test_memcpy(str, c, ii);
		ii++;
	}
	ii = 0;
	while (ii < 5)
	{
		char str[ii];
		strcpy(str, "");
		test_memcpy(str, c, ii);
		ii++;
	}
	printf("can be a good job ;)\n");
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2024/10/30 20:09:44 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*b_cpy;

	b_cpy = b;
	while (len--)
		*b_cpy++ = c;
	return (b);
}

/*
//
#include "error_msg.h"
#include <ctype.h>
#include <string.h>
// MAIN
int test_memset(char *str, int c, int len, int buf_size)
{
	char	s1[1000];
	char	s2[1000];
	int		ii = 0;

	strcpy(s1, str);
	strcpy(s2, str);
	memset(s1, c, len);
	ft_memset(s2, c, len);
	while (ii < len)
	{
		if (s1[ii] != s2[ii])
		{
			printf("differents output for str=[%s]\nmemset(str) = [%s]\n\
			ft_memset(str) = [%s]\nlen/str_bufsize = %d\nbuf_size = %d\n"\
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
	int jj = 0;
	char c = 'a';

	while (ii < 6)
	{
		char str[ii];
		strcpy(str, "abc\n");
		jj = 0;
		while (jj < ii)
		{
			test_memset(str, c, jj, ii);
			jj++;
		}
		strcpy(str, "");
		jj = 0;
		while (jj < ii)
		{
			test_memset(str, c, jj, ii);
			jj++;
		}
		ii++;
	}
	printf("can be a good job ;)\n");
}
*/

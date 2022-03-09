/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2022/03/09 19:06:05 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	len_needle;
	unsigned int	ii;
	unsigned int	jj;

	if (!haystack)
		return (NULL);
	len_needle = ft_strlen(needle);
	if (!len_needle)
		return ((char *) haystack);
	if (len < len_needle)
		return (NULL);
	else
		len -= len_needle - 1;
	ii = 0;
	while (ii < len && haystack[ii])
	{
		jj = 0;
		while (needle[jj] == haystack[ii + jj] && haystack[ii + jj] && jj < len_needle)
			jj++;
		if (jj == len_needle)
			return ((char *) haystack + ii);
		else
			ii++;
	}
	return (NULL);
}

/*
//
#include <stdio.h>
#include <string.h>
// MAIN
int test_strnstr(char *haystack, char *needle, unsigned int len)
{
	char *r1, *r2;
	if ((r1 = ft_strnstr(haystack, needle, len)) !=\
   	(r2 = strnstr(haystack, needle, len)))
	{
		printf("[BUG] strnstr:\n\
			outputs differents when:\n\
			haystack = [%s]; needle = [%s]; len = %d\n\
			ft_strnstr(haystack, needle, len)	= [%s]\n\
		   	strnstr(haystack, needle, len))		= [%s]\n",\
			haystack, needle, len, r1, r2);
	
		return (1);
	}
	return (0);
}

int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		test_strnstr("", "", i);
		test_strnstr("abc", "", i);
		test_strnstr("", "abc", i);
		test_strnstr("abc", "a", i);
		test_strnstr("abc", "b", i);
		test_strnstr("abc", "c", i);
		test_strnstr("abc", "X", i);
		test_strnstr("zabc", "abc", i);
		test_strnstr("abcz", "abc", i);
	}
		test_strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZE", 99);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2022/03/04 15:53:06 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* // CODE SOURCE
char * strnstr(const char *s, const char *find, size_t slen)
{
	char c, sc;
	size_t len;

	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if ((sc = *s++) == '\0' || slen-- < 1)
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char			*haystack_cpy;
	unsigned int	len_cpy;

	if (!ft_strlen(needle))
		return ((char *) haystack);
	haystack_cpy = (char *) haystack;
	len_cpy = len;
	while (len_cpy--)
	{
		if (ft_strncmp(haystack_cpy, (char *) needle, len))
		{
			haystack_cpy++;
		}
		else
		{
			return ((char *) ((long unsigned int) haystack_cpy - \
					  (long unsigned int) haystack));
		}
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
	test_strnstr("", "", 0);
	test_strnstr("abc", "", 0);
	test_strnstr("abc", "", 1);
	test_strnstr("", "abc", 1);
	test_strnstr("", "abc", 4);
	test_strnstr("abc", "b", 1);
	test_strnstr("zabcabcd", "abc", 4);
	test_strnstr("abc", "C", 2);
}
*/

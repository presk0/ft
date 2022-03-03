/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2022/03/03 17:59:31 by supersko         ###   ########.fr       */
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
char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	unsigned int	needle_len;
	unsigned int	haystack_len;
	unsigned int	i_haystack;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return (haystack);
	haystack_len = ft_strlen(haystack);
	i_haystack = 0;
	while (haystack[i_haystack] && i_haystack + needle_len <= len)
	{
		if (ft_strncmp((haystack + i_haystack), needle, len))
		{
			i_haystack++;
		}
		else
		{
			return (haystack + i_haystack);
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

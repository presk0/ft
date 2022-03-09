/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2022/03/09 18:12:35 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char			*haystack_cpy;
	unsigned int	len_cmp;
	unsigned int	len_needle;

	len_needle = ft_strlen(needle);
	if (!haystack || !needle)
		return (NULL);
	if (!len_needle)
		return ((char *) haystack);
	haystack_cpy = (char *) haystack;
	len_cmp = len;
	if (len_needle < len_cmp)
		len_cmp = len_needle;
	while (len-- >= len_needle && *haystack_cpy)
	{
		if (ft_strncmp(haystack_cpy, (char *) needle, len_cmp))
		{
			haystack_cpy++;
		}
		else
		{
			return (haystack_cpy);
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
}
*/

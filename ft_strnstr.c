/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2022/03/01 14:12:33 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strnstr(char *haystack, char *needle, unsigned int len)
{
	unsigned int	needle_len;
	unsigned int	haystack_len;
	unsigned int	i_haystack;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return (haystack);
	haystack_len = _strlen(haystack);
	i_haystack = 0;
	while (i_haystack < len && haystack[i_haystack])
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
	return ((char *) 0);
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

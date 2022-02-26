/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2022/02/26 16:56:23 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(char *s, int c)
{
	unsigned int	ii;
	int				absent;

	ii = 0;
	absent = 1;
	while (s[ii] != '\0')
	{
		if (s[ii] == c)
			absent = 0;
		ii++;
	}
	if (c == '\0')
		return (s + ii);
	else if (absent)
		return (0);
	else
	{
		while (ii >= 0)
		{
			if (s[ii] == c)
			{
				return (s + ii);
			}
			ii--;
		}
	}
	return (0);
}

#include "error_msg.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int test_strrchr(char *str, char c)
{
	unsigned int ret;

	ret = strrchr(str, c) - ft_strrchr(str, c);
	if (ret)
	{
		printf("[bug] at str: %s, c: %c\n", str, c);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int ii = 0;
	test_strrchr("abcbi", 'b');
	test_strrchr("abc", '\0');
	test_strrchr("", 'a');
	test_strrchr("", '\0');
	printf("test finished\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2022/02/26 11:04:49 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	ii;

	ii = 0;
	while (ii < n)
	{
		if (s1[ii] == s2[ii]) 
		{
			if (s1[ii] == '\0')
				return (0);
			ii++;
		}
		else
			return (s1[ii] - s2[ii]);
	}
	return (0);
}

#include "error_msg.h"
#include <string.h>

int test_strncmp(char *s1, char *s2, int len)
{
	int		ii = 0;

	if (ft_strncmp(s1, s2, len) == strncmp(s1, s2, len))
		return (1);
	else
	{
		printf("[BUG]\ns1 = %s, s2 %s\nstrncmp = %d\nft_strncmp = %d\nlen = %d\n\n", s1, s2, strncmp(s1, s2, len), ft_strncmp(s1, s2, len), len);
		return (0);
	}
}

int	main(int argc, char *argv[])
{
	int ii = 0;
	char s1[100];
	char s2[100];
	int ret = 1;

	while (ii < 5)
	{
		strcpy(s1, "abc");
		strcpy(s2, "abc");
		test_strncmp(s1, s2, ii);

		strcpy(s1, "abc");
		strcpy(s2, "");
		test_strncmp(s1, s2, ii);

		strcpy(s1, "");
		strcpy(s2, "abc");
		test_strncmp(s1, s2, ii);

		strcpy(s1, "abz");
		strcpy(s2, "abcfghdfgh");
		test_strncmp(s1, s2, ii);

		strcpy(s1, "abcfghdfgh");
		strcpy(s2, "abz");
		test_strncmp(s1, s2, ii);

		strcpy(s1, "abcfgz");
		strcpy(s2, "abcfghdfgh");
		test_strncmp(s1, s2, ii);

		strcpy(s1, "abcfghdfgh");
		strcpy(s2, "abcfgz");
		test_strncmp(s1, s2, ii);
		ii++;
	}
	printf("can be a good job ;)\n");
}

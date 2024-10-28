/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2024/10/28 13:50:22 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n--)
		if (*str1++ != *str2++)
			return (*(--str1) - *(--str2));
	return (0);
}

/*
int test_memcmp(char *s1, char *s2, int len)
{
	int		ii = 0;

	if (ft_memcmp(s1, s2, len) == memcmp(s1, s2, len))
		return (1);
	else
	{
		printf("[BUG]\ns1 = %s, s2 %s\nmemcmp \
			= %d (=%c)\nft_memcmp = %d\nlen = %d\n\
		\n", s1, s2, memcmp(s1, s2, len), ft_memcmp(s1, s2, len), len);
		return (0);
	}
}

int	main(int argc, char *argv[])
{
	int ii = 0;
	char s1[100];
	char s2[100];
	int ret = 1;

	while (ii < 3)
	{
		strcpy(s1, "a");
		strcpy(s2, "");
		test_memcmp(s1, s2, ii);

		strcpy(s1, "");
		strcpy(s2, "a");
		test_memcmp(s1, s2, ii);

		strcpy(s1, "a");
		strcpy(s2, "a");
		test_memcmp(s1, s2, ii);

		strcpy(s1, "a");
		strcpy(s2, "b");
		test_memcmp(s1, s2, ii);

		strcpy(s1, "b");
		strcpy(s2, "a");
		test_memcmp(s1, s2, ii);

		strcpy(s1, "a");
		strcpy(s2, "ab");
		test_memcmp(s1, s2, ii);

		strcpy(s1, "ab");
		strcpy(s2, "a");
		test_memcmp(s1, s2, ii);
		ii++;
	}
}
*/

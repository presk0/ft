/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2022/02/25 19:50:50 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, void *src, unsigned int len)
{
	unsigned int	ii;

	ii = 0;
	if (dst < src)
	{
		while (ii < len)
		{
			((char *) dst)[ii] = ((char *) src)[ii];
			ii++;
		}
	}
	else
	{
		while (ii < len)
		{
			((char *) dst)[len - ii] = ((char *) src)[len - ii];
			ii++;
		}
	}
	return (dst);
}

//Ne fait pas la diff avec memcpy
#include "error_msg.h"
#include <ctype.h>
#include <string.h>

int test_memmove(char *to_cpy, int len)
{
	char	s1[5] = "1111";
	char	s2[5] = "2222";
	int		ii = 0;

	memmove(s1, to_cpy, len);
	ft_memmove(s2, to_cpy, len);
	while (ii < len)
	{
		if (s1[ii] != s2[ii])
		{
			printf("differents output for str=[%s]\nmemmove(str) = [%s]\nft_memmove(str) = [%s]\n", to_cpy, s1, s2);
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
		strcpy(str, "aaaaaa");
		test_memmove(str, ii);
		ii++;
	}
	ii = 0;
	while (ii < 6)
	{
		char str[ii];
		strcpy(str, "");
		test_memmove(str, ii);
		ii++;
	}
	printf("can be a good job ;)\n");
}

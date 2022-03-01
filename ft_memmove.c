/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2022/03/01 13:54:36 by supersko         ###   ########.fr       */
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
			((char *) dst)[len - ii - 1] = ((char *) src)[len - ii - 1];
			ii++;
		}
	}
	return (dst);
}

/*
//
//Ne fait pas la diff avec memcpy
#include "error_msg.h"
#include <ctype.h>
#include <string.h>
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	ii;
// MAIN
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
	
int test_memmove(int len)
{
	char	s1[] = "0123456789";
	char	s2[] = "0123456789";
	int		ii = 0;

	memmove(s1 + 3, s1 + 2, len);
	ft_memmove(s2 + 3, s2 + 2, len);
	if (ft_strncmp(s1, s2, 1000))
	{
		printf("memmove(str) = [%s]\n\
			ft_memmove(str) = [%s]\n\
			len = %d\n\
			", s1, s2, len);
		printf("\n");
		return (1);
	}
	memmove(s1 + 3, s1 + 2, len);
	ft_memmove(s2 + 3, s2 + 2, len);
	if (ft_strncmp(s1, s2, 1000))
	{
		printf(" memmove(str) = [%s]\n\
			ft_memmove(str) = [%s]\n\
			len = %d\n\
			", s1, s2, len);
		printf("\n");
		return (1);
	}
	memmove(s1 + 3, s1 + 3, len);
	ft_memmove(s2 + 3, s2 + 3, len);
	if (ft_strncmp(s1, s2, 1000))
	{
		printf(" memmove(str) = [%s]\n\
			ft_memmove(str) = [%s]\n\
			len = %d\n\
			", s1, s2, len);
		printf("\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int ii = 0;

	while (ii < 5)
	{
		test_memmove(ii);
		ii++;
	}
	ii = 0;
	while (ii < 6)
	{
		test_memmove(ii);
		ii++;
	}
	printf("can be a good job ;)\n");
}
*/

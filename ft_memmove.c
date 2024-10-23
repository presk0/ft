/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2024/10/23 18:41:39 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		ft_memcpy(dst, src,len);
//		while (i < len)
//		{
//			((char *) dst)[i] = ((char *) src)[i];
//			i++;
//		}
	}
	else
	{
		while (i < len)
		{
			((char *) dst)[len - i - 1] = ((char *) src)[len - i - 1];
			i++;
		}
	}
	return (dst);
}
/*
//
#include <string.h>
#include <stdio.h>
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
}
*/

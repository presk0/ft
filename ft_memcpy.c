/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2024/10/18 13:54:35 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0 || dst == src)
		return (dst);
	while (i < len)
	{
		((char *) dst)[i] = ((char *) src)[i];
		i++;
	}
	return (dst);
}

/*
#include <string.h>
#include <stdio.h>
int test_memcpy(char *to_cpy, int len)
{
	int		result = 0;
	char	s1[1000];
	char	s2[1000];
	int		i = 0;

	memcpy(s1, to_cpy, len);
	ft_memcpy(s2, to_cpy, len);
	while (i < len)
	{
		if (s1[i] != s2[i])
		{
			result = 1;
			break ;
		}
		i++;
	}
	return (result);
}

int main(int argc, char *argv[]) 
{
	printf
	test_memcpy(argv[1], atoi(argv[2]));
}
*/

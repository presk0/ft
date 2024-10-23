/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2024/10/23 23:41:14 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *ndl, size_t len)
{
	size_t		i;
	char		*p;
	size_t		ndl_len;

	p = (char *)str;
	i = 0;
	ndl_len = ft_strlen(ndl);
	if (p && len >= ndl_len)
		while (*p && i++ <= len - ndl_len)
			if (!ft_strncmp(p++, ndl, ndl_len))
				return (--p);
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char **argv)
{
	printf("original: %s\n", strnstr(argv[1], argv[2], atoi(argv[3])));
	printf("ft_funct: %s\n", ft_strnstr(argv[1], argv[2], atoi(argv[3])));
}
*/

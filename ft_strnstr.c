/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2024/10/27 16:28:28 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *ndl, size_t len)
{
	size_t		i;
	char		*p_str;
	size_t		ndl_len;

	p_str = (char *)str;
	if (*ndl == '\0')
		return (p_str);
	i = 0;
	ndl_len = ft_strlen(ndl);
	if (len >= ndl_len)
		while (*p_str && i++ <= len - ndl_len)
			if (!ft_strncmp(p_str++, ndl, ndl_len))
				return (--p_str);
	return (NULL);
}

#include <stdio.h>
#include <bsd/string.h>
int	main(int argc, char **argv)
{
	//printf("original: %s\n", strnstr(0, argv[2], atoi(argv[3])));
	printf("ft_funct: %s\n", ft_strnstr(0, argv[2], atoi(argv[3])));
}


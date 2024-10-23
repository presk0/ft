/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2024/10/23 19:03:12 by nidionis         ###   ########.fr       */
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
	if (!ndl_len)
		return (p);
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
	//printf("original: %s\n", strnstr(argv[1], argv[2], atoi(argv[3])));
	printf("ft_funct: %s\n", ft_strnstr(argv[1], argv[2], atoi(argv[3])));
}
char	*ft_strnstr(const char *str, const char *ndl, size_t len)
{
	size_t		i_str;
	size_t		i_ndl;
	size_t		i_cmp;
	int			found;

	i_str = -1;
	found = 1;
	if (!ft_strlen(ndl))
		return ((char *)str);
	while (*(str + ++i_str) && i_str < len)
	{
		i_ndl = 0;
		if (*(str + i_str) == *(ndl))
		{
			i_cmp = i_str;
			found = 1;
			while (*(str + i_cmp) && *(ndl + i_ndl)
				&& i_ndl < len && i_cmp < len)
				if (*(str + i_cmp++) != *(ndl + i_ndl++))
					found = 0;
			if (found && !*(ndl + i_ndl))
				return ((char *)str + i_str);
		}
	}
	return (NULL);
}
*/

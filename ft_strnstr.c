/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2024/11/10 16:26:18 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *ndl, size_t len)
{
	char		*p_str;
	size_t		ndl_len;

	p_str = (char *)str;
	if (!*ndl)
		return (p_str);
	ndl_len = ft_strlen(ndl);
	if (len >= ndl_len)
	{
		while (*p_str && len && len + 1 >= ndl_len)
		{
			if (!ft_strncmp(p_str, ndl, ndl_len))
				return (p_str);
			p_str++;
			len--;
		}
	}
	return (NULL);
}

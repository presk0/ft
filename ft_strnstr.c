/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2024/10/14 15:02:07 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// from nickdotht 
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

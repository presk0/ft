/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_wd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:09:43 by supersko          #+#    #+#             */
/*   Updated: 2024/10/27 14:59:29 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_next_wd(char *str, char sep)
{
	if (str)
	{
		if (!(*str))
			return (NULL);
		else
			while (*str && *str != sep)
				str++;
		if (*str && *str == sep)
			while (*str == sep)
				str++;
	}
	return (str);
}

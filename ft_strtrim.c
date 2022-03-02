/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:33:46 by supersko          #+#    #+#             */
/*   Updated: 2022/03/02 18:14:22 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	ii;
	char			*ret;

	start = 0;
	end = ft_strlen( (char *) s1);
	while (s1[start] && ft_strchr( (char *) set, s1[start]))
		start++;
	while (end > start && ft_strchr( (char *) set, s1[end]))
		end--;
	ret = malloc(sizeof(char *) * (end - start + 1));
	if (!ret)
		return (NULL);
	ii = 0;
	while (start < end)
	{
		ret[ii] = s1[start + ii];
		ii++;
	}
	return (ret);
}

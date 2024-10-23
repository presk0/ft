/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:33:46 by supersko          #+#    #+#             */
/*   Updated: 2024/10/23 19:15:30 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	char	*new_str;
	size_t	end;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	end = ft_strlen(s1);
	while (end > 0 && ft_strchr(set, s1[end]))
		end--;
	new_str = ft_calloc(end + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	ret = new_str;
	while (end-- && *s1)
		*new_str++ = *s1++;
	return (ret);
}

/*
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	printf("%s\n", ft_strtrim(argv[1], argv[2]));
}
*/

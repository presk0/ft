/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:33:46 by supersko          #+#    #+#             */
/*   Updated: 2022/03/04 20:59:12 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_trimable(char c, char *trimset)
{
	int	ii;

	ii = 0;
	while (trimset[ii])
	{
		if (trimset[ii] == c)
			return (1);
		ii++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	ii;
	char			*ret;

	start = 0;
	end = ft_strlen( (char *) s1) - 1;
	while (s1[start] && is_trimable((char) s1[start], (char *) set))
		start++;
	while (end > start &&  is_trimable((char) s1[end], (char *) set))
		end--;
	ret = malloc(sizeof(char *) * (end - start + 1));
	if (!ret)
		return (NULL);
	ii = 0;
	while (start <= end--)
	{
		ret[ii] = s1[start + ii];
		ii++;
	}
	ret[ii] = '\0';
	return (ret);
}

#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[100];

	strcpy(s, "-   asd asd   dfgh     --");
	printf("[%s] -> [%s]\n", s, ft_strtrim(s, " -"));
}

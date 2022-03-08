/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:33:46 by supersko          #+#    #+#             */
/*   Updated: 2022/03/05 13:18:42 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_trimable(char c, char *trimset)
{
	int	ii;

	ii = 0;
	while (trimset[ii])
	{
		if (trimset[ii] == c || !trimset[ii])
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
	end = ft_strlen((char *) s1);
	while (s1[start] && is_trimable((char) s1[start], (char *) set))
		start++;
	while (end > start && is_trimable((char) s1[end], (char *) set))
		end--;
	ret = malloc(sizeof(char *) * (end - start + 1));
	if (!ret)
		return (NULL);
	ii = 0;
	while (start <= end && end)
	{
		ret[ii] = s1[start + ii];
		ii++;
		end--;
	}
	ret[ii] = '\0';
	return (ret);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[100];

	strcpy(s, "-   asd asd   dfgh     --");
	printf("[%s] -> [%s]\n", s, ft_strtrim(s, " -"));
	strcpy(s, "    --");
	printf("[%s] -> [%s]\n", s, ft_strtrim(s, " -"));
	strcpy(s, "fdb dfb  sdfb fbbb");
	printf("[%s] -> [%s]\n", s, ft_strtrim(s, " -"));
	strcpy(s, "asd");
	printf("[%s] -> [%s]\n", s, ft_strtrim(s, " -"));
	strcpy(s, "");
	printf("[%s] -> [%s]\n", s, ft_strtrim(s, " -"));
}
*/

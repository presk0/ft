/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:55:04 by supersko          #+#    #+#             */
/*   Updated: 2024/10/18 13:57:21 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		s_len;
	char	*scpy;

	s_len = ft_strlen(s1);
	scpy = (char *) malloc(sizeof(char) * (s_len + 1));
	if (!scpy)
		return ((char *) 0);
	i = 0;
	while (i < s_len)
	{
		scpy[i] = s1[i];
		i++;
	}
	scpy[i] = '\0';
	return (scpy);
}
/*
//
#include <stdio.h>
// MAIN
int main(void)
{
	char *cpy;

	cpy = ft_strdup("La chaine");
	printf("%s\n", cpy);
	free(cpy);
}
*/

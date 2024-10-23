/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:55:04 by supersko          #+#    #+#             */
/*   Updated: 2024/10/23 18:50:30 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t		i;
	size_t		s_len;
	char		*scpy;

	if (!str)
		return (NULL);
	s_len = ft_strlen(str);
	scpy = (char *) calloc(s_len + 1, sizeof(char));
	if (!scpy)
		return (NULL);
	i = 0;
	while (i < s_len)
		scpy[i] = str[i++];
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

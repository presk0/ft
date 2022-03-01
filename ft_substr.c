/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2022/03/01 14:09:40 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib>

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	unsigned int	ii;
	char			*newstr;

	newstr = (char *) malloc(sizeof(char) * (len + 1));
	ii = 0;
	while (s[ii++])
		;
	if (!newstr && ii <= start)
		return (NULL);
	ii = 0;
	while (ii < len && s[ii + start])
	{
		newstr[ii] = s[ii + start];
		ii++;
	}
	newstr[ii] = '\0';
	return (newstr);
}
/*
//
#include <string.h>
#include <stdlib.h>
// MAIN

int	main(void)
{
	;
}
*/

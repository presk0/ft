/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2022/03/11 17:06:56 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > s_len)
	{
		substr = (char *)malloc(sizeof(char) * 1);
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	substr = (char *)malloc(sizeof(char) * (s_len - start + 1));
	if (substr == NULL)
		return (NULL);
	while (i < len && s[start] != '\0')
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*return_val;

	if (!s)
		return (NULL);
	substr = (char *) malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (start--)
		if (!*s++)
		{
			substr[0] = '\0';
			return (substr);
		}
	return_val = substr;
	while (len-- && *s)
	{
		*substr++ = *s++;
	}
	*substr = '\0';
	return (return_val);
}
*/

/*
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// MAIN

int	main(void)
{
	char	str[100];
	char	*output;
	int		start;
	int		len;

	strcpy(str, "une chaine");
	start	= 1;
	len		= 3;
	output = ft_substr(str, start, len);
	printf("ft_substr(\"%s\", %d, %d) => [%s]\n", str, start, len, output);
}
*/

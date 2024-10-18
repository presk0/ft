/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2024/10/18 14:14:29 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			len_s1;
	unsigned int	i;
	char			*ret;

	if (!s1)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen((char *) s1);
	ret = (char *) malloc(sizeof(char) * (ft_strlen((char *) s2) + len_s1 + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[i - len_s1])
	{
		ret[i] = s2[i - len_s1];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
/*
//
#include <stdio.h>
#include <string.h>
#include "libft.h"
// MAIN
int main(void)
{
	char s1[1000];
	char s2[1000];
	char *verif;

	strcpy(s1, "ch1 ");
	strcpy(s2, "ch2");
	verif = ft_strjoin(s1, s2);
	if (ft_strncmp(verif, "ch1 et ch2", 20))
	{
		printf("Pb at ft_strjoin\n");
	}
	free(verif);
}
*/

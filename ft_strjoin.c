/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2024/10/23 19:50:05 by nidionis         ###   ########.fr       */
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
	len_s1 = ft_strlen(s1);
	ret = (char *) calloc(ft_strlen(s2) + len_s1 + 1, sizeof(char));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		ret[i] = s1[i];
	i = -1;
	while (s2[++i])
		ret[i + len_s1] = s2[i];
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

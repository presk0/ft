/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2024/10/30 20:20:03 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			len_s1;
	size_t			len_s2;
	char			*ret;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ret = malloc(len_s2 + len_s1 + 1 * sizeof(char));
	*ret = '\0';
	if (!ret)
		return (NULL);
	if (s1)
		ft_strlcpy(ret, s1, ++len_s1);
	if (s2)
		ft_strlcat(ret, s2, len_s1 + len_s2);
	return (ret);
}

/* peut remplacer ft_strlc..
	i = -1;
	if (s1)
		while (++i < len_s1)
			ret[i] = s1[i];
	i = -1;
	if (s2)
		while (s2[++i])
			ret[i + len_s1] = s2[i];
*/
/*
//
#include <stdio.h>
#include <string.h>
#include "libft.h"
// MAIN
int main(int argc, char **argv)
{
	char *s1 = argv[1];
	char *s2 = argv[2];
	char *verif;

	verif = ft_strjoin(s1, s2);
	printf("\n");
	printf("my_funct: %s\n", verif);
	free(verif);
}
*/

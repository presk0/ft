/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:31:55 by supersko          #+#    #+#             */
/*   Updated: 2022/03/07 20:01:43 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static unsigned int	ft_strlench(char const *s, char c)
{
	unsigned int	ii;

	ii = 0;
	while (s[ii] && s[ii] != c)
		ii++;
	return (ii);
}

static unsigned int	ft_wdcnt(char *s, char c)
{
	unsigned int	ii;
	unsigned int	count;

	count = 0;
	ii = 0;
	while (*s)
	{
		if (*s == c)
		{
			s++;
			while (*s == c && *s)
				s++;
		}
		else
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

// Desole pour la conversion de char en string
char	**ft_split(char const *s, char c)
{
	char			**ret;
	unsigned int	i_let;
	unsigned int	i_wd;
	unsigned int	nb_wd;

	if (!s)
		return (NULL);
	nb_wd = ft_wdcnt((char *) s, c);
	ret = (char **) malloc((nb_wd + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	i_wd = 0;
	while (i_wd < nb_wd)
	{
		ret[i_wd] = (char *) malloc(sizeof(char) * (ft_strlench(s, c) + 1));
		if (!ret[i_wd])
			return (NULL);
//		printf("len %u\n", ft_strlench(s, c));
		i_let = 0;
		while (*s && *s != c)
			ret[i_wd][i_let++] = *s++;
//		printf("let %u\n", i_let);
		ret[i_wd][i_let] = '\0';
		while (*s == c)
			s++;
		i_wd++;
	}
	ret[nb_wd] = (char *) NULL;
	return (ret);
}
#include <string.h>
// MAIN
int main(void)
{
	char	**sortie;
	int		ii;

	sortie = ft_split("Phrase de      test", ' ');
	ii = 0;
	while (sortie[ii] != NULL)
		 printf("%s\n", sortie[ii++]); 

	sortie = ft_split("P", '');
	ii = 0;
	while (sortie[ii] != NULL)
		 printf("%s\n", sortie[ii++]); 

	sortie = ft_split("", ' ');
	ii = 0;
	while (sortie[ii] != NULL)
		 printf("%s\n", sortie[ii++]); 

/*
	char s[10];
	strcpy(s, "");
	printf("for [%s] -> %d\n", s, ft_wdcnt(s, ' '));
	strcpy(s, "  ");
	printf("for [%s] -> %d\n", s, ft_wdcnt(s, ' '));
	strcpy(s, "a");
	printf("for [%s] -> %d\n", s, ft_wdcnt(s, ' '));
	strcpy(s, "a ");
	printf("for [%s] -> %d\n", s, ft_wdcnt(s, ' '));
	strcpy(s, " a");
	printf("for [%s] -> %d\n", s, ft_wdcnt(s, ' '));
	strcpy(s, " a ");
	printf("for [%s] -> %d\n", s, ft_wdcnt(s, ' '));
	strcpy(s, "  aa  ");
	printf("for [%s] -> %d\n", s, ft_wdcnt(s, ' '));
	strcpy(s, "bb   bb");
	printf("for [%s] -> %d\n", s, ft_wdcnt(s, ' '));
*/
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:31:55 by supersko          #+#    #+#             */
/*   Updated: 2022/03/05 12:28:24 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_trimable(char c, char *trimset)
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

static unsigned int	ft_strlench(char const *s, char c)
{
	unsigned int	ii;

	ii = 0;
	while (s[ii] != c)
		ii++;
	return (ii);
}

// Retourne le nombre de mots separe par c
// on compte le nombre de separateurs
// (les premiers et derniers exclus)
// et on ajoute 1 car il y a toujours
// un poteau (mot) de plus que de fils :
// |mot|sep|mot| => 1 sep = 2 mots

static unsigned int	ft_wdcnt(char *s, char c)
{
	unsigned int	ii;
	unsigned int	count;
	char			c_cpy[2];

	count = 0;
	ii = 0;
	c_cpy[0] = c;
	c_cpy[1] = '\0';
	while (s[ii])
	{
		if (is_trimable(s[ii], c_cpy))
		{
			ii++;
			while (is_trimable(s[ii], c_cpy))
				ii++;
		}
		else
		{
			count++;
			while (!is_trimable(s[ii], c_cpy) && s[ii])
				ii++;
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
	unsigned int	i_str;
	unsigned int	nb_wd;

	nb_wd = ft_wdcnt((char *) s, c);
	ret = (char **) malloc((nb_wd + 1) * sizeof(char *));
	*(ret + nb_wd) = (char *) NULL;
	i_wd = 0;
	i_str = 0;
	while (i_wd < nb_wd)
	{
		ret[i_wd] = (char *) malloc(ft_strlench(s + i_str, c) + 1);
		i_let = 0;
		while (s[i_str] != c)
			ret[i_wd][i_let++] = s[i_str++];
		ret[i_wd][++i_let] = '\0';
		while (s[i_str] == c)
			i_str++;
		i_wd++;
	}
	return (ret);
}
/*
#include <stdio.h>
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
		 */
	/*
	char s[10];
	strcpy(s, "");
	printf("for [%s] -> %d\n", s, ft_wdcnt(s, " "));
	strcpy(s, "  ");
	printf("for [%s] -> %d\n", s, ft_wdcnt(s, " "));
	strcpy(s, "a");
	printf("for [%s] -> %d\n", s, ft_wdcnt(s, " "));
	strcpy(s, "a ");
	printf("for [%s] -> %d\n", s, ft_wdcnt(s, " "));
	strcpy(s, " a");
	printf("for [%s] -> %d\n", s, ft_wdcnt(s, " "));
	strcpy(s, " a ");
	printf("for [%s] -> %d\n", s, ft_wdcnt(s, " "));
	strcpy(s, "  aa  ");
	printf("for [%s] -> %d\n", s, ft_wdcnt(s, " "));
	strcpy(s, "bb   bb");
	printf("for [%s] -> %d\n", s, ft_wdcnt(s, " "));
}
	*/

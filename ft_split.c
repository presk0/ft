/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:31:55 by supersko          #+#    #+#             */
/*   Updated: 2022/03/05 11:42:41 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int      is_trimable(char c, char *trimset)
{
    int ii;

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

static unsigned int	ft_wdcnt(char *s, char *c)
{
	unsigned int	ii;
	unsigned int	count;

	count = 0;
	ii = 0;
	while (s[ii])
	{
		if (is_trimable(s[ii], c))
		{
			ii++;
			while (is_trimable(s[ii], c))
				ii++;
		}
		else
		{
			count++;
			while (!is_trimable(s[ii], c) && s[ii])
				ii++;
		}
	}
	return count;
}

// Desole pour la conversion de char en string
char **ft_split(char const *s, char c)
{
	char			**ret;
	unsigned int	lettab_ind;
	unsigned int	wd_ind;
	unsigned int	letter_ind;
	unsigned int	nb_wd;
	char			c_cpy[2];

	c_cpy[0] = c;
	c_cpy[1] = '\0';
	nb_wd = ft_wdcnt((char *) s, c_cpy);
	ret = (char **) malloc((++nb_wd) * sizeof(char*));
	*(ret + nb_wd) = (char *) NULL;
	wd_ind = 0;
	letter_ind = 0;
	while (wd_ind < nb_wd)	
	{
		ret[wd_ind] = (char*) malloc(sizeof(char) * (ft_strlench(s + letter_ind, c) + 1));
		lettab_ind = 0;
		while (s[letter_ind] != c)
		{
			ret[wd_ind][lettab_ind] = s[letter_ind];
			lettab_ind++;
			letter_ind++;
		}
		ret[wd_ind][++lettab_ind] = '\0';
		while (s[letter_ind] == c)
			letter_ind++;
		wd_ind++;
	}
	return (ret);
}
#include <stdio.h>
#include <string.h>
// MAIN
int main(void)
{
	/*
	char	**sortie;
	int		ii;

	sortie = ft_split("Phrase de      test", ' ');
	ii = 0;
	while (sortie[ii] != NULL)
		 printf("%s\n", sortie[ii++]); 
*/
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

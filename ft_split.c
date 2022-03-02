/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:31:55 by supersko          #+#    #+#             */
/*   Updated: 2022/03/02 18:35:54 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static unsigned int	ft_wdcnt(char *s, int c)
{
	unsigned int	ii;
	unsigned int	count;
	unsigned int	end;

	ii = 0;
	count = 0;
	end = ft_strlen(s);
	while (!s[end] || s[end] == c)
		end--;
	while (s[ii] == c)
		ii++;
	while (ii <= end)
	{
		if (s[ii] == c)
		{
			count++;
			while (s[ii] == c)
				ii++;
		}
		ii++;
	}
	return ++count;
}

char **ft_split(char const *s, char c)
{
	char			**ret;
	unsigned int	lettab_ind;
	unsigned int	wd_ind;
	unsigned int	letter_ind;
	unsigned int	nb_wd;

	nb_wd = ft_wdcnt((char *) s, c);
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
/*
//
#include <stdio.h>
// MAIN
int main(void)
{
	char	**sortie;
	int		ii;

	sortie = ft_split("Phrase de      test", ' ');
	ii = 0;
	while (sortie[ii] != NULL)
		 printf("%s\n", sortie[ii++]); 
}
*/

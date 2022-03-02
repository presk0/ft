/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdcnt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:51:11 by supersko          #+#    #+#             */
/*   Updated: 2022/03/01 18:50:42 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int     ft_strlen(char *s);

// Retourne le nombre de mots separe par c
// on compte le nombre de separateurs
// (les premiers et derniers exclus)
// et on ajoute 1 car il y a toujours
// un poteau (mot) de plus que de fils :
// |mot|sep|mot| => 1 sep = 2 mots

unsigned int	ft_wdcnt(char *s, int c)
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
/*
//
#include <stdio.h>
// MAIN
//
int main(void)
{
	printf("%u\n", ft_wdcnt("asdf", 'd'));
	printf("%u\n", ft_wdcnt("dasdfdd", 'd'));
	printf("%u\n", ft_wdcnt("  ceci est une phrase  ", ' '));
	printf("%u\n", ft_wdcnt("ceci est une phrase", ' '));
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:31:55 by supersko          #+#    #+#             */
/*   Updated: 2022/03/08 18:15:01 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_trimable(char c, char trimer)
{
	if (c == trimer)
		return (1);
	return (0);
}

static unsigned int	ft_strlen_char(char const *s, char c)
{
	unsigned int	ii;

	ii = 0;
	while (s[ii] != c && s[ii])
		ii++;
	return (ii);
}

char	*next_wd(char *s, char  c)
{
	while (*s && *s == c)
		s++;
	return (s);
}

static unsigned int	ft_wdcnt(char *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		if (is_trimable(*s, c) && *s)
		{
			while (is_trimable(*s, c) && *s)
				s++;
		}
		else
		{
			count++;
			while (!is_trimable(*s, c) && *s)
				s++;
		}
	}
	return (count);
}

// Desole pour la conversion de char en string
char	**ft_split(char const *s, char c)
{
	char			**ret;
	unsigned int	i_wd;
	unsigned int	nb_wd;
	size_t			wd_len;
	char			*s_cpy;

	if (!s || !c)
		return (NULL);
	s_cpy = (char *) s;
	s_cpy = next_wd(s_cpy, c);
	nb_wd = ft_wdcnt( s_cpy, c);
	ret = (char **) malloc((nb_wd + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	i_wd = 0;
	while (i_wd < nb_wd && *s_cpy)
	{
		wd_len = ft_strlen_char(s_cpy, c);
		ret[i_wd] = (char *) malloc(sizeof(char) * (++wd_len));
		if (!ret[i_wd])
			return (NULL);
		ft_strlcpy(ret[i_wd++], s_cpy, wd_len);
		s_cpy += wd_len;
		s_cpy = next_wd(s_cpy, c);
	}
	*(ret + nb_wd) = NULL;
	return (ret);
}

/*
//
#include <stdio.h>
#include <string.h>
// MAIN
int main(void)
{
	char	**sortie;
	int		ii;

	printf("=====================================\n");
	sortie = ft_split("P t", ' ');
	ii = 0;
	while (sortie[ii] != NULL)
		 printf("%s\n", sortie[ii++]); 

	printf("=====================================\n");
	sortie = ft_split(" ", ' ');
	ii = 0;
	while (sortie[ii] != NULL)
		 printf("%s\n", sortie[ii++]); 

	printf("=====================================\n");
	sortie = ft_split("t", ' ');
	ii = 0;
	while (sortie[ii] != NULL)
		 printf("%s\n", sortie[ii++]); 

	printf("=====================================\n");
	sortie = ft_split(" t", ' ');
	ii = 0;
	while (sortie[ii] != NULL)
		 printf("%s\n", sortie[ii++]); 

	printf("=====================================\n");
	sortie = ft_split("t " , ' ');
	ii = 0;
	while (sortie[ii] != NULL)
		 printf("%s\n", sortie[ii++]); 

	printf("=====================================\n");
	sortie = ft_split(" t ", ' ');
	ii = 0;
	while (sortie[ii] != NULL)
		 printf("%s\n", sortie[ii++]); 
//
//	char s[10];
//	strcpy(s, "");
//	printf("for [%s] -> %d\n", s, ft_wdcnt(s, ' '));
//	strcpy(s, "  ");
//	printf("for [%s] -> %d\n", s, ft_wdcnt(s, ' '));
//	strcpy(s, "a");
//	printf("for [%s] -> %d\n", s, ft_wdcnt(s, ' '));
//	strcpy(s, "a ");
//	printf("for [%s] -> %d\n", s, ft_wdcnt(s, ' '));
//	strcpy(s, " a");
//	printf("for [%s] -> %d\n", s, ft_wdcnt(s, ' '));
//	strcpy(s, " a ");
//	printf("for [%s] -> %d\n", s, ft_wdcnt(s, ' '));
//	strcpy(s, "b b");
//	printf("for [%s] -> %d\n", s, ft_wdcnt(s, ' '));
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:31:55 by supersko          #+#    #+#             */
/*   Updated: 2022/03/11 18:06:42 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static char
	**ft_alloc_split(char const *s, char c)
{
	size_t	i;
	char	**split;
	size_t	total;

	i = 0;
	total = 0;
	while (s[i])
	{
		if (s[i] == c)
			total++;
		i++;
	}
	split = (char**)malloc(sizeof(s) * (total + 2));
	if (!split)
		return (NULL);
	return (split);
}

void
	*ft_free_all_split_alloc(char **split, size_t elts)
{
	size_t	i;

	i = 0;
	while (i < elts)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static void
	*ft_split_range(char **split, char const *s,
		t_split_next *st, t_split_next *lt)
{
	split[lt->length] = ft_substr(s, st->start, st->length);
	if (!split[lt->length])
		return (ft_free_all_split_alloc(split, lt->length));
	lt->length++;
	return (split);
}

static void
	*ft_split_by_char(char **split, char const *s, char c)
{
	size_t			i;
	t_split_next	st;
	t_split_next	lt;

	i = 0;
	lt.length = 0;
	lt.start = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			st.start = lt.start;
			st.length = (i - lt.start);
			if (i > lt.start && !ft_split_range(split, s, &st, &lt))
				return (NULL);
			lt.start = i + 1;
		}
		i++;
	}
	st.start = lt.start;
	st.length = (i - lt.start);
	if (i > lt.start && i > 0 && !ft_split_range(split, s, &st, &lt))
		return (NULL);
	split[lt.length] = 0;
	return (split);
}

char
	**ft_split(char const *s, char c)
{
	char	**split;

	if (!(split = ft_alloc_split(s, c)))
		return (NULL);
	if (!ft_split_by_char(split, s, c))
		return (NULL);
	return (split);
}
*/

static unsigned int	ft_strlen_char(char const *s, char c)
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

char	**make_tab(char **ret, char const *s, char c, unsigned int nb_wd)
{
	unsigned int	i_wd;
	unsigned int	wd_len;

	i_wd = 0;
	while (i_wd < nb_wd)
	{
		while (ft_strlen_char(s, c) == 0)
			s++;
		wd_len = ft_strlen_char(s, c);
		if (wd_len != 0)
		{
			ret[i_wd] = (char *) malloc(sizeof(char) * (++wd_len));
			if (!ret[i_wd])
				return (NULL);
		}
		ft_strlcpy(ret[i_wd], s, wd_len);
		ret[i_wd][wd_len] = '\0';
		s += wd_len;
		i_wd++;
	}
	return (ret);
}

// Desole pour la conversion de char en string
char	**ft_split(char const *s, char c)
{
	char			**ret;
	unsigned int	nb_wd;

	if (!s)
		return (NULL);
	nb_wd = ft_wdcnt((char *) s, c);
	ret = (char **) malloc((nb_wd + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	ret = make_tab(ret, s, c, nb_wd);
	ret[nb_wd] = (char *) NULL;
	return (ret);
}

/*
//
#include <string.h>
#include <stdio.h>
// MAIN

void put_header(void)
{
	printf("****************************************************\n");
}

int main(void)
{
	char	**sortie;
	int		ii;

	put_header();
	sortie = ft_split("Phrase de      test", ' ');
	ii = 0;
	while (sortie[ii] != NULL)
		 printf("%s\n", sortie[ii++]); 

	put_header();
	sortie = ft_split("P", ' ');
	ii = 0;
	while (sortie[ii] != NULL)
		 printf("%s\n", sortie[ii++]); 

	put_header();
	sortie = ft_split("", ' ');
	ii = 0;
	while (sortie[ii] != NULL)
		 printf("%s\n", sortie[ii++]); 

	put_header();
	sortie = ft_split(" a ", ' ');
	ii = 0;
	while (sortie[ii] != NULL)
		 printf("%s\n", sortie[ii++]); 

	put_header();
	sortie = ft_split(" a", ' ');
	ii = 0;
	while (sortie[ii] != NULL)
		 printf("%s\n", sortie[ii++]); 

	put_header();
	sortie = ft_split("a ", ' ');
	ii = 0;
	while (sortie[ii] != NULL)
		 printf("%s\n", sortie[ii++]); 

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
}
*/

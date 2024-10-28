/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:31:55 by supersko          #+#    #+#             */
/*   Updated: 2024/10/28 22:27:22 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_split(char **tab)
{
	if (tab)
	{
		while (*tab)
		{
			free(*tab);
			*tab++ = NULL;
		}
		free(tab);
		tab = NULL;
	}
}

static size_t	append_line(char *str, char sep, char **ret, size_t i_wd)
{
	size_t	wd_len;

	if (!str)
		return (0);
	wd_len = 0;
	while (str[wd_len] && str[wd_len] != sep)
		wd_len++;
	ret[i_wd] = (char *) malloc((wd_len + 1) * sizeof(char));
	if (!ret[i_wd])
		ft_free_split(ret);
	else
		ft_strlcpy(ret[i_wd], str, wd_len + 1);
	return (wd_len);
}

static int	ft_wd_count(char *str, char sep)
{
	int		wd_nb;

	wd_nb = 0;
	if (!str)
		return (0);
	if (sep == '\0')
		return (1);
	while (*str)
	{
		while (*str == sep)
			str++;
		if (*str)
			wd_nb++;
		while (*str && *str != sep)
			str++;
	}
	return (wd_nb);
}

static char	**make_tab(char **ret, char const *s, char c, unsigned int nb_wd)
{
	size_t	i_wd;
	size_t	wd_len;

	i_wd = 0;
	while (i_wd < nb_wd)
	{
		if (c)
			while (*s == c)
				s++;
		wd_len = append_line((char *)s, c, ret, i_wd);
		if (!ret[i_wd++])
			return (NULL);
		s += wd_len;
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char			**ret;
	unsigned int	nb_wd;

	nb_wd = ft_wd_count((char *) s, c);
	ret = (char **) malloc((nb_wd + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	ret[nb_wd] = NULL;
	ret = make_tab(ret, s, c, nb_wd);
	return (ret);
}

/*
#include <stdio.h>
int main(int argc, char **argv) {
	(void)argc;
	//char **tab = ft_split("", 0);
	//char **tab = ft_split(argv[1], argv[2][0]);
	char **tab = ft_split("\0aa\0bb", '\0');
	//printf("%i\n", ft_wd_count(argv[1], argv[2][0]));
	while (*tab)
		printf("%s\n", *tab++);
}

static char	*ft_get_next_wd(char *str, char sep)
{
	if (str)
	{
		if (!*str)
			return (NULL);
		else
			while (*str && *str != sep)
				str++;
		if (*str && *str == sep)
			while (*str == sep)
				str++;
	}
	return (str);
}

static int	ft_wd_count(char *str, char sep)
{
	int		wd_nb;

	wd_nb = 0;
	if (str)
	{
		if (sep == '\0' && *str)
			return (1);
		while (*str == sep)
			str++;
		while (*str)
		{
			str = ft_get_next_wd(str, sep);
			if (str)
				wd_nb++;
		}
	}
	return (wd_nb);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:31:55 by supersko          #+#    #+#             */
/*   Updated: 2024/10/27 16:30:21 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		wd_len = ft_strlen_char((char *)s, c);
		if (wd_len)
		{
			ret[i_wd] = (char *) ft_calloc(wd_len + 1, sizeof(char));
			if (!ret[i_wd])
			{
				ft_free_split(ret);
				return (NULL);
			}
		}
		ft_strlcpy(ret[i_wd++], s, wd_len + 1);
		s += wd_len;
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char			**ret;
	unsigned int	nb_wd;

	nb_wd = ft_wd_count((char *) s, c);
	ret = (char **) ft_calloc((nb_wd + 1), sizeof(char *));
	if (!ret)
		return (NULL);
	ret = make_tab(ret, s, c, nb_wd);
	return (ret);
}

/*
#include <stdio.h>
int main(int argc, char **argv) {
	(void)argc;
	char **tab = ft_split("", 0);
	//char **tab = ft_split(argv[1], argv[2][0]);
	//char **tab = ft_split("\0aa\0bb", '\0');
	while (*tab)
		printf("%s\n", *tab++);
}
*/

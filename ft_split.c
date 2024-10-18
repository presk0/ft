/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:31:55 by supersko          #+#    #+#             */
/*   Updated: 2024/10/18 13:39:03 by nidionis         ###   ########.fr       */
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
		while (*s == c)
			s++;
		wd_len = ft_strlen_char((char *)s, c);
		if (wd_len != 0)
		{
			ret[i_wd] = (char *) malloc(sizeof(char) * (wd_len + 1));
			if (!ret[i_wd])
			{
				ft_free_split(ret);
				return (NULL);
			}
		}
		ft_strlcpy(ret[i_wd], s, wd_len + 1);
		s += wd_len;
		i_wd++;
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
	ret = make_tab(ret, s, c, nb_wd);
	ret[nb_wd] = NULL;
	return (ret);
}
/*
int main(int argc, char **argv) {
	printf("%s\n", ft_split(argv[1], atoi(argv[2])));
}
*/

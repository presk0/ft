/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wd_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:09:34 by supersko          #+#    #+#             */
/*   Updated: 2022/04/21 15:29:43 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wd_count(char *sentence, char sep)
{
	int		wd_nb;

	if (sentence)
	{
		while (*sentence == sep)
			sentence++;
		wd_nb = 0;
		while (*sentence)
		{
			sentence = ft_get_next_wd(sentence, sep);
			if (sentence != NULL)
				wd_nb++;
		}
	}
	return (wd_nb);
}

#include <stdio.h>
int main()
{
	printf("%d\n", ft_wd_count(NULL, 0));
	printf("%d\n", ft_wd_count("a", ' '));
	printf("%d\n", ft_wd_count(" a", ' '));
	printf("%d\n", ft_wd_count("a ", ' '));
	printf("%d\n", ft_wd_count(" a ", ' '));
	printf("%d\n", ft_wd_count("a a", ' '));
	printf("%d\n", ft_wd_count("a a ", ' '));
	printf("%d\n", ft_wd_count(" a a", ' '));
	printf("%d\n", ft_wd_count(" a a ", ' '));
}

/*
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wd_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:09:34 by supersko          #+#    #+#             */
/*   Updated: 2022/04/21 14:43:14 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wd_count(char *sentence, char sep)
{
	int		wd_nb;

	while (*sentence == sep)
		sentence++;
	wd_nb = 0;
	while (*sentence)
	{
		sentence = ft_get_next_wd(sentence, sep);
		if (sentence != NULL);
			wd_nb++;
	}
	return (wd_nb);
}

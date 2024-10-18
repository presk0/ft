/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_wd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:09:43 by supersko          #+#    #+#             */
/*   Updated: 2024/10/18 13:26:40 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_next_wd(char *sentence, char sep)
{
	if (!(*sentence))
		sentence = NULL;
	else
		while (*sentence && *sentence != sep)
			sentence++;
	if (*sentence && *sentence == sep)
		while (*sentence == sep)
			sentence++;
	return (sentence);
}

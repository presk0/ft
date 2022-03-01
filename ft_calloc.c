/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:44:37 by supersko          #+#    #+#             */
/*   Updated: 2022/03/01 13:52:38 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

void	*ft_calloc(unsigned int count, unsigned int size)
{
	void			*ptr;
	unsigned int	ii;

	ii = 0;
	ptr = malloc(count * size);
	ft_bzero(ptr, count * size);
	return (ptr);
}

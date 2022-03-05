/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:36:39 by supersko          #+#    #+#             */
/*   Updated: 2022/03/05 12:34:04 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus.h"

void	ft_lsadd_back(t_list **lst, t_list *new)
{
	new->next = NULL;
	if (*lst == NULL)
		*lst = new;
	while ((*lst)->next != NULL)
		*lst = (*lst)->next;
	(*lst)->next = new;
}

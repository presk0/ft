/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:36:39 by supersko          #+#    #+#             */
/*   Updated: 2022/03/11 14:23:30 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//void	ft_lsadd_front(t_list **lst, t_list *new)
//{
//	if (lst && new)
//	{
//		new->next = *lst;
//		*lst = new;
//	}
//}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*buff;

	if (lst && new)
	{
		buff = *lst;
		*lst = new;
		new->next = buff;
	}
}

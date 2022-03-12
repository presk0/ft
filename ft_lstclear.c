/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:31:49 by supersko          #+#    #+#             */
/*   Updated: 2022/03/11 20:40:51 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_item;

	if (lst && del)
	{
		while (*lst)
		{
			next_item = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = next_item;
		}
	}
}

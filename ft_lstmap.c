/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:02:44 by supersko          #+#    #+#             */
/*   Updated: 2022/03/12 12:30:45 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*item;

	if (lst && f && del)
	{
		ret = ft_lstnew((*f)(lst->content));
		while (lst)
		{
			item = ft_lstnew((*f)(lst->content));
			ft_lstadd_back(ret, item);
			if (!item)
			{
				ft_lstclear(item, del);
				return (NULL);
			}
			lst = lst->next;
		}
		return (ret);
	}
	return (NULL);
}

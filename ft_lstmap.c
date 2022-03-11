/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:02:44 by supersko          #+#    #+#             */
/*   Updated: 2022/03/11 16:10:55 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**ret;

	if (lst && f)
	{
		ret = ft_lstnew((*f)(lst->content));
		while (lst)
		{
			ft_lstadd_back(ret, ft_lstnew((*f)(lst->content)));
			lst = lst->next;
		}
	}
	return (ret);
}

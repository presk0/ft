/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:02:44 by supersko          #+#    #+#             */
/*   Updated: 2024/11/10 16:04:55 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*ret;
	t_list	*new;
	void	*cont;

	if (!f || !del)
		ft_errmsg("[ft_lstmap] functions missing\n");
	ret = NULL;
	while (lst)
	{
		cont = f(lst->content);
		new = ft_lstnew(cont);
		if (!new)
		{
			del(cont);
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, new);
		lst = lst->next;
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:36:39 by supersko          #+#    #+#             */
/*   Updated: 2022/03/04 12:02:42 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new = NULL;
	new->content = content;
	new->next = NULL;
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:29:46 by supersko          #+#    #+#             */
/*   Updated: 2022/03/05 13:19:15 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ___BONUS_H__
# define ___BONUS_H__

#include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct	s_list	*next;
}					t_list;

t_list *ft_lstnew(void *content);

void ft_lstadd_front(t_list **lst, t_list *new);

int ft_lstsize(t_list *lst);

t_list *ft_lstlast(t_list *lst);

void ft_lstadd_back(t_list **lst, t_list *new);

void ft_lstdelone(t_list *lst, void (*del)(void *));

void ft_lstclear(t_list **lst, void (*del)(void *));

void ft_lstiter(t_list *lst, void (*f)(void *));

#endif

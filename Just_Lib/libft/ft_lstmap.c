/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Applies a function to each node and returns a new string.              */
/*   • Prototype:   STRUCT ( struct *, f(), f() )                             */
/* ************************************************************************** */
#include "just_lib.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*_list;
	t_list		*elem;
	void		*cont;

	_list = NULL;
	elem = NULL;
	cont = 0;
	while (lst)
	{
		cont = f(lst->content);
		elem = ft_lstnew(cont);
		if (!elem)
		{
			del(cont);
			ft_lstclear(&_list, del);
			return (NULL);
		}
		if (!_list)
			_list = elem;
		else
			ft_lstadd_back(&_list, elem);
		lst = lst->next;
	}
	return (_list);
}

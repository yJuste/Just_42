/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Print the list.                                                        */
/*   • Prototype:   VOID ( list * )                                           */
/* ************************************************************************** */
#include "../just_lib.h"

// can add any other type in the line 6.

void	ft_print_list(t_list *_list)
{
	while (_list != NULL)
	{
		printf("%d -> ", *(int *)_list->data);
		_list = _list->next;
	}
	printf("NULL\n");
}

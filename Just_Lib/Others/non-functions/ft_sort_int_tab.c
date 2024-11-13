/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Sorts an arr of int.                                                   */
/*   • Prototype:   VOID ( int *, int )                                       */
/*        -> size_t                                                           */
/* ************************************************************************** */
#include "../just_lib.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	if (size < 0)
		return ;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
	return ;
}

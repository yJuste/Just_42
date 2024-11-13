/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Returns all int from in start to in end.                               */
/*   • Prototype:   INT * ( int, int )                                        */
/*        -> malloc, size_t                                                   */
/* ************************************************************************** */
#include "just_lib.h"

// only [1, 2, 3] up

int	*ft_range_up(int start, int end)
{
	int			*tab;
	size_t		i;

	i = 0;
	if (start >= end)
		return (NULL);
	tab = malloc(sizeof(int) * (end - start));
	while (start < end)
	{
		tab[i] = end;
		i++;
		end++;
	}
	return (tab);
}

// [1, 2, 3] up & [3, 2, 1] down

int	*ft_range_up_down(int start, int end)
{
	int			*res;
	size_t		len;
	size_t		i;

	i = 0;
	len = end - start;
	if (len < 0)
		len = -len;
	res = malloc(sizeof(int) * (len + 1));
	while (i < len)
	{
		if (start < end)
		{
			res[i] = start;
			start++;
			i++;
		}
		else
		{
			res[i] = start;
			start--;
			i++;
		}
	}
	return (res);
}

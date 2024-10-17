/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Returns all int from in start to in end.                               */
/*   • Prototype:   INT ( int **, int, int )                                  */
/*        -> malloc, size_t                                                   */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int start, int end)
{
	size_t		i;

	i = 0;
	if (start >= end)
	{
		*range = 0;
		return (0);
	}
	*range = malloc(sizeof(int) * (end - start));
	if (!*range)
		return (0);
	while (end > start)
	{
		(*range)[i] = start;
		start++;
		i++;
	}
	return (i);
}

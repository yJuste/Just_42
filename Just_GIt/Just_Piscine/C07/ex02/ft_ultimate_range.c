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

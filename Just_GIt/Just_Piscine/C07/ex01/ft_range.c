/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int			*tab;
	size_t		i;

	i = 0;
	if (start >= end)
		return (NULL);
	tab = (int *)malloc(sizeof(int) * (end - start));
	while (start < end)
	{
		tab[i] = end;
		i++;
		end++;
	}
	return (tab);
}

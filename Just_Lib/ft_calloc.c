/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Allocates and initializes memory.                                      */
/*   • Prototype:   VOID* ( int count, int size_of )                          */
/*        -> malloc                                                           */
/* ************************************************************************** */
#include <stdlib.h>

// Don't forget to free !

void	*ft_calloc(int size, int size_of)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = malloc(size_of * size);
	if (ptr == 0)
		return (NULL);
	while (i < size_of * size)
		ptr[i++] = 0;
	return (ptr);
}

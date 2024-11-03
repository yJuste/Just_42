/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Allocates memory on the heap.                                          */
/*   • Prototype:   VOID * ( int )                                            */
/*        -> malloc                                                           */
/* ************************************************************************** */
#include <stdlib.h>

// Don't forget to free !

void	*ft_malloc(int size)
{
	void		*ptr;

	if (size < 0)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	return (ptr);
}

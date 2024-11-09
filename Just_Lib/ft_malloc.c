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
#include "just_lib.h"

// Don't forget to free !

void	*ft_malloc(size_t size)
{
	void		*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	return (ptr);
}

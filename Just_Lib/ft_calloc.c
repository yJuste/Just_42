/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Allocates and initializes memory.                                      */
/*   • Prototype:   VOID * ( int, int )                                       */
/*        -> malloc                                                           */
/* ************************************************************************** */
#include <stdlib.h>

// Don't forget to free !
// Don't forget to put sizof(..) in size .

void	*ft_calloc(size_t size)
{
	size_t		i;
	char		*ptr;

	i = 0;
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	while (i < size)
		ptr[i++] = '\0';
	return (ptr);
}

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

void	*ft_calloc(int size_of, int size)
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

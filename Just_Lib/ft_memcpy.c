/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Copies to n bytes a memory block.                                      */
/*   • Prototype:   VOID * ( void *, void *, size_t )                         */
/*        -> size_t                                                           */
/* ************************************************************************** */
#include <stdlib.h>

// more commonly used with structures or arrays.
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	while (n--)
		((char *)dst)[n] = ((const char *)src)[n];
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Moves one chain into another.                                          */
/*   • Prototype:   VOID * ( void *, void *, size_t )                         */
/*        -> size_t                                                           */
/* ************************************************************************** */
#include "just_lib.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;

	if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			((char *)dest)[i - 1] = ((char *)src)[i - 1];
			i--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

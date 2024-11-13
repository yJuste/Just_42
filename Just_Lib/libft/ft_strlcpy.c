/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • (null)                                                                 */
/*   • Prototype:   SIZE_T * ( char *, char *, size_t )                       */
/*        -> size_t                                                           */
/* ************************************************************************** */
#include "just_lib.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		s;
	size_t		i;

	s = 0;
	while (src[s])
		s++;
	if (dstsize == 0)
		return (s);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (s);
}

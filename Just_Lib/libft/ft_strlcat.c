/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dl;
	size_t		sl;
	size_t		i;
	size_t		j;

	sl = 0;
	while (src[sl])
		sl++;
	if (!dst && dstsize == 0)
		return (sl);
	dl = 0;
	while (dst[dl] && dl < dstsize)
		dl++;
	if (dstsize <= dl)
		return (sl + dstsize);
	i = 0;
	j = dl;
	while (src[i] && (dl + i < dstsize - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dl + sl);
}

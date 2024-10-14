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
#include <stdlib.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		dlen;
	size_t		slen;
	size_t		i;
	size_t		j;

	dlen = 0;
	slen = 0;
	while (dest[dlen] && dlen < size)
		dlen++;
	while (src[slen])
		slen++;
	if (size <= dlen)
		return (slen + size);
	i = 0;
	j = dlen;
	while (src[i] && dlen + i < size - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dlen + slen);
}

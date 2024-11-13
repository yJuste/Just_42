/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Searches for a char in a str starting from the end.                    */
/*   • Prototype:   CHAR * ( char *, int )                                    */
/*        -> size_t                                                           */
/* ************************************************************************** */
#include "just_lib.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;

	i = ft_strlen(s);
	while (s[i] != (char)c && i > 0)
		i--;
	if (s[i] == (char) c)
		return ((char *)s + i);
	return (NULL);
}

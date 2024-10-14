/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Finds a char from a str.                                               */
/*   • Prototype:   CHAR* ( char *s, char *c )                                */
/* ************************************************************************** */
#include <stdlib.h>

const char	*ft_findchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		++s;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Returns the index of the exact occurences of a str.                    */
/*   • Prototype:   SIZE_T ( char *, char * )                                 */
/*        -> size_t                                                           */
/* ************************************************************************** */
#include <stdlib.h>

const char	*ft_findchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (s);
		++s;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t		i;

	i = 0;
	if (!s || !accept)
		return (NULL);
	while (s[i])
	{
		if (ft_findchr(accept, s[i]) == 0)
			break ;
		++i;
	}
	return (i);
}

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
#include "just_lib.h"

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		if (ft_findchr(accept, s[i]) == 0)
			break ;
		++i;
	}
	return (i);
}

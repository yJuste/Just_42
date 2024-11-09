/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Finds the 1st occurrence of a str.                                     */
/*   • Prototype:   CHAR * ( char *, char * )                                 */
/*        -> size_t                                                           */
/* ************************************************************************** */
#include "just_lib.h"

const char	*ft_strpbrk(const char *s1, const char *s2)
{
	size_t		i;

	i = 0;
	while (*s1)
	{
		i = 0;
		while (s2[i])
		{
			if (*s1 == s2[i])
				return (s1);
			i++;
		}
		s1++;
	}
	return (NULL);
}

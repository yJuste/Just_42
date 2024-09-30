/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Finds the 1st occurrence of a str.                                     */
/*   • Prototype:   CHAR* ( char *s1, char *s2 )                              */
/*        -> size_t                                                           */
/* ************************************************************************** */
#include <stdlib.h>

const char	*ft_strpbrk(const char *s1, const char *s2)
{
	size_t		i;

	if (!s1 || !s2)
		return (0);
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

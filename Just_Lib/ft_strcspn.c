/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Returns the index to reject.                                           */
/*   • Prototype:   INT ( char *, char * )                                    */
/*        -> size_t                                                           */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strcspn(const char *s, const char *reject)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s || !reject)
		return (0);
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

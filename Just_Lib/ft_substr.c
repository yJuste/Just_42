/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Returns an n-byte char sub-str from a start.                           */
/*   • Prototype:   CHAR * ( char *, char * )                                 */
/*        -> size_t                                                           */
/* ************************************************************************** */
#include "just_lib.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	char		*res;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (ft_strlen(s) - start < len)
		i = ft_strlen(s) - start;
	else
		i = len;
	res = ft_calloc(i + 1, sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (j < i)
	{
		res[j] = s[start + j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

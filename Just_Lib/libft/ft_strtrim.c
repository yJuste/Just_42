/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Trims the first and last char in a str.                                */
/*   • Prototype:   CHAR * ( char *, char * )                                 */
/*        -> size_t                                                           */
/* ************************************************************************** */
#include "just_lib.h"

static int	ft_ischar_trim(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		start;
	size_t		end;
	char		*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_ischar_trim(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_ischar_trim(s1[end - 1], set))
		end--;
	str = ft_calloc(end - start + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}

static int	ft_ischar_trim(char c, char const *set)
{
	size_t		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

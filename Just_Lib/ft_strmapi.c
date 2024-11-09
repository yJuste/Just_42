/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Returns a str to which a function is applied on each element.          */
/*   • Prototype:   CHAR * ( char *, f() )                                    */
/*        -> size_t                                                           */
/* ************************************************************************** */
#include "just_lib.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	size_t		length;
	char		*n_tab;

	if (!s)
		return (NULL);
	length = 0;
	while (s[length])
		length++;
	n_tab = ft_calloc(length + 1, sizeof(char));
	if (!n_tab)
		return (NULL);
	i = 0;
	while (i < length)
	{
		n_tab[i] = f(i, s[i]);
		i++;
	}
	n_tab[length] = '\0';
	return (n_tab);
}

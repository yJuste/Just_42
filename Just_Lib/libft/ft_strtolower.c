/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Returns the lowercase equivalent of an uppercase string.               */
/*   • Prototype:   CHAR * ( char * )                                         */
/*        -> malloc, size_t                                                   */
/* ************************************************************************** */
#include "just_lib.h"

const char	*ft_strtolower(const char *str)
{
	int		i;
	char	*lwr_str;

	i = 0;
	lwr_str = ft_strdup(str);
	if (!lwr_str)
		return (NULL);
	while (lwr_str[i])
	{
		lwr_str[i] = ft_tolower(lwr_str[i]);
		i++;
	}
	return (lwr_str);
}

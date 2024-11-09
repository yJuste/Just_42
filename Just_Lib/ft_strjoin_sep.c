/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Gathers str of char based on a separator.                              */
/*   • Prototype:   CHAR * ( int, char **, char * )                           */
/*        -> malloc, size_t                                                   */
/* ************************************************************************** */
#include "just_lib.h"

static int	ft_len_sep_join(char **strs, char *sep, size_t size);

char	*ft_strjoin_sep(char **strs, char *sep, size_t size)
{
	size_t		i;
	char		*tab;

	i = 0;
	if (size == 0)
	{
		tab = malloc(sizeof(char));
		*tab = 0;
		return (tab);
	}
	tab = malloc(sizeof(char) * ft_len_sep_join(strs, sep, size));
	if (!tab)
		return (NULL);
	*tab = 0;
	while (i < size)
	{
		ft_strcat(tab, strs[i]);
		if (i < size - 1)
			ft_strcat(tab, sep);
		i++;
	}
	return (tab);
}

static int	ft_len_sep_join(char **strs, char *sep, size_t size)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len = len + (size - 1) * ft_strlen(sep) + 1;
	return (len);
}

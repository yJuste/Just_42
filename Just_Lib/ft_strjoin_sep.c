/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Gathers str of char based on a separator.                              */
/*   • Prototype:   CHAR* ( int size, char **strs, char *sep )                */
/*        -> malloc                                                           */
/* ************************************************************************** */
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_len(char **strs, int size, char *sep)
{
	size_t		i;
	int			len;

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

char	*ft_strcat(char *dest, const char *src)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
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
	tab = malloc(sizeof(char) * ft_len(strs, size, sep));
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

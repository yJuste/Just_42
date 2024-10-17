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
#include <stdlib.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

size_t	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	size_t		i;
	char		*dest;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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

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

const char	*ft_strtolower(const char *str);
int			ft_tolower(int c);
char		*ft_strdup(const char *src);

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

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char	*ft_strdup(const char *src)
{
	char		*dest;
	size_t		i;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

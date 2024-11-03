/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Converts an int to a str.                                              */
/*   • Prototype:   CHAR * ( int )                                            */
/*        -> malloc, size_t                                                   */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_itoa(int nbr);
void	ft_itoa_next(int nbr, char *res, int len);
char	*ft_strdup(const char *src);

// utilise : getconf INT_MAX pour connaitre la valeure max d'un int.
char	*ft_itoa(int nbr)
{
	int		n;
	int		len;
	char	*res;

	n = nbr;
	len = 0;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nbr <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_itoa_next(nbr, res, len);
	return (res);
}

void	ft_itoa_next(int nbr, char *res, int len)
{
	res[len] = '\0';
	if (nbr == 0)
	{
		res[0] = '0';
		return ;
	}
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		res[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return ;
}

char	*ft_strdup(const char *src)
{
	char		*dest;
	size_t		i;

	i = 0;
	if (!src)
		return (NULL);
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

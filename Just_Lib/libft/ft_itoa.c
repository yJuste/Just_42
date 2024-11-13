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
#include "just_lib.h"

// utilise : getconf INT_MAX pour connaitre la valeure max d'un int.

static void	ft_itoa_next(int n, char *res, int len);

char	*ft_itoa(int n)
{
	int		nbr;
	int		len;
	char	*res;

	nbr = n;
	len = 0;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nbr <= 0)
		len++;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	ft_itoa_next(n, res, len);
	return (res);
}

static void	ft_itoa_next(int n, char *res, int len)
{
	res[len] = '\0';
	if (n == 0)
	{
		res[0] = '0';
		return ;
	}
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n)
	{
		res[--len] = n % 10 + '0';
		n /= 10;
	}
	return ;
}

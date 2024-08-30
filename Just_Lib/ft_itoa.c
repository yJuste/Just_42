/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Converts an int to a str.                                              */
/*   • Prototype:   CHAR* ( int nbr )                                         */
/*        -> malloc ( sizeof(type) * size )                                   */
/*        -> size_t                                                           */
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

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

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

int	ft_len(int nbr)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

void	ft_res(int nbr, int len, char *result)
{
	if (nbr == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return ;
	}
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	result[len--] = '\0';
	while (nbr > 0)
	{
		result[len - 1] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
}

char	*ft_itoa(int nbr)
{
	int		len;
	char	*result;
	int		flg;

	flg = nbr < 0;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	if (flg)
		nbr = -nbr;
	len = ft_len(nbr) + flg;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	ft_res(nbr, len - 1, result);
	return (result);
}

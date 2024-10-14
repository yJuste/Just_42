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
/*   • Prototype:   CHAR* ( int nbr )                                         */
/*        -> malloc, size_t                                                   */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_itoa(int nbr);
char	*ft_strdup(char *src);
int		ft_len(int nbr, int base_len);
void	ft_res(int nbr, int len, char *result);
size_t	ft_strlen(const char *str);

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
	len = ft_len(nbr, 10) + flg;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	ft_res(nbr, len - 1, result);
	return (result);
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

int	ft_len(int nbr, int base_len)
{
	int		len;
	long	n;

	len = 0;
	n = nbr;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= base_len;
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

size_t	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

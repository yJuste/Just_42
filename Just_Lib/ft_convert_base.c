/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Converts an int from one base to another.                              */
/*   • Prototype:   CHAR* ( char *nbr, char *base_from, char *base_to )       */
/*        -> malloc, size_t                                                   */
/* ************************************************************************** */
#include <stdlib.h>

// file 1/2

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		ft_check_base(char *base);
int		ft_len(int nbr, int base_len);
void	ft_putnbr_base(int nbr, char *base, char *res, int *i);

// file 2/2

int		ft_atoi_base(char *str, char *base);
int		ft_res(char *str, char *base, int i);
size_t	ft_strlen(const char *str);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		nb;
	int		len;
	char	*res;

	i = 0;
	if (ft_check_base(base_from) < 2 || ft_check_base(base_to) < 2)
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	len = ft_len(nb, ft_check_base(base_to));
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	ft_putnbr_base(nb, base_to, res, &i);
	res[i++] = '\0';
	return (res);
}

int	ft_check_base(char *base)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
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

void	ft_putnbr_base(int nbr, char *base, char *res, int *i)
{
	int long	n;
	int			b;

	b = ft_check_base(base);
	n = nbr;
	if (n < 0)
	{
		res[(*i)++] = '-';
		n *= -1;
	}
	if (n >= b)
	{
		ft_putnbr_base(n / b, base, res, i);
		ft_putnbr_base(n % b, base, res, i);
	}
	else
		res[(*i)++] = base[n];
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
void	ft_putnbr_base(int nbr, char *base, char *res, int *i);
size_t	ft_strlen(const char *str);
int		ft_check_base(char *str);
int		ft_findchr(char *base, char c);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		i;
	int		sign;
	char	*res;

	res = malloc(sizeof(char) * 42);
	if (ft_check_base(base_from) < 2 || ft_check_base(base_to) < 2)
		return (0);
	nb = 0;
	i = 0;
	sign = 1;
	while (nbr[i] == ' ' || (nbr[i] >= '\t' && nbr[i] <= '\r'))
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_findchr(base_from, nbr[i]) != -1)
		nb = nb * ft_check_base(base_from) + (ft_findchr(base_from, nbr[i]));
	i = 0;
	ft_putnbr_base((nb * sign), base_to, res, &i);
	res[i] = 0;
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

void	ft_putnbr_base(int nbr, char *base, char *res, int *i)
{
	int long	nbl;
	int			b;

	b = ft_check_base(base);
	nbl = nbr;
	if (nbl < 0)
	{
		(*i)++;
		res[*i] = '-';
		nbl *= -1;
	}
	if (nbl >= b)
		ft_putnbr_base(nbl / b, base, res, i);
	(*i)++;
	res[*i] = base[nbl % b];
	return ;
}

int	ft_findchr(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

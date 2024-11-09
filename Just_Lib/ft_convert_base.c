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
/*   • Converts an int from one base to another.                              */
/*   • Prototype:   CHAR * ( char *, char *, char * )                         */
/*        -> malloc, size_t                                                   */
/* ************************************************************************** */
#include "just_lib.h"

static int	ft_findchr_convert(char *base, char c);
static void	ft_putnbr_base_convert(int nbr, char *base, char *res, int *i);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		i;
	int		sign;
	char	*res;

	res = ft_calloc(42, sizeof(char));
	if (ft_check_base(base_from) < 2 || ft_check_base(base_to) < 2)
		return (0);
	nb = 0;
	i = 0;
	sign = 1;
	while (nbr[i] == ' ' || (nbr[i] >= '\t' && nbr[i] <= '\r'))
		i++;
	if (nbr[i] == '-')
		sign = -sign;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (ft_findchr_convert(base_from, nbr[i]) != -1)
		nb = nb * ft_check_base(base_from)
			+ (ft_findchr_convert(base_from, nbr[i]));
	i = 0;
	ft_putnbr_base_convert((nb * sign), base_to, res, &i);
	res[i] = 0;
	return (res);
}

static void	ft_putnbr_base_convert(int nbr, char *base, char *res, int *i)
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
		ft_putnbr_base_convert(nbl / b, base, res, i);
	(*i)++;
	res[*i] = base[nbl % b];
	return ;
}

static int	ft_findchr_convert(char *base, char c)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

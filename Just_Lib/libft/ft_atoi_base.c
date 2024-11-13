/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Converts alpha into int from a base.                                   */
/*   • Prototype:   INT ( char *, char * )                                    */
/*        -> size_t                                                           */
/* ************************************************************************** */
#include "just_lib.h"

static int	ft_res(char *str, char *base, int i);

int	ft_atoi_base(char *str, char *base)
{
	int			sign;
	size_t		i;

	i = 0;
	sign = 1;
	if (!ft_check_base(base))
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (ft_res(str, base, i) * sign);
}

static int	ft_res(char *str, char *base, int i)
{
	int		res;
	int		j;

	res = 0;
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
				break ;
			j++;
		}
		if (base[j] == '\0')
			break ;
		res = res * ft_strlen(base) + j;
		i++;
	}
	return (res);
}

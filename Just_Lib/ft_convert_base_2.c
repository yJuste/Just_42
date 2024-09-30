/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
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

int	ft_atoi_base(char *str, char *base)
{
	int			sign;
	size_t		i;

	if (!ft_check_base(base))
		return (0);
	i = 0;
	sign = 1;
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

int	ft_res(char *str, char *base, int i)
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

size_t	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

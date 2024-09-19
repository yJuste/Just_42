/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • First Library.                                                         */
/* ************************************************************************** */
#include "main.h"

// ----------PROTOTYPE-------------
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_isspace(char c);
int		ft_atoi(char *str);
// --------------------------------

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	char	sign;
	double	result;

	i = 0;
	result = 0;
	sign = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		if (result > 2147483647 || result < -2147483648)
			return (0);
		i++;
	}
	if (sign % 2 == 1)
		return (-result);
	return (result);
}

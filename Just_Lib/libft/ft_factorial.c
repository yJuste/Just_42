/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Returns the factorial of a num.                                        */
/*   • Prototype:   INT ( int )                                               */
/* ************************************************************************** */
#include "just_lib.h"

// Iterative function

int	ft_factorial(int nbr)
{
	int		i;
	int		res;

	i = 1;
	res = 1;
	if (nbr < 0)
		return (0);
	while (i <= nbr)
	{
		res = res * i;
		i++;
	}
	return (res);
}

// Recursive function

int	ft_recursive_factorial(int nbr)
{
	if (nbr < 0)
		return (0);
	if (nbr > 1)
		return (nbr * ft_factorial(nbr - 1));
	return (1);
}

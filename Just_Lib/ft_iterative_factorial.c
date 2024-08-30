/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Returns the factorial of a num.                                        */
/*   • Prototype:   INT ( int nbr )                                           */
/*        -> size_t                                                           */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_iterative_factorial(int nbr)
{
	size_t		i;
	int			res;

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

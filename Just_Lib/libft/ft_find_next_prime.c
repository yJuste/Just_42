/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Finds the next prime.                                                  */
/*   • Prototype:   INT ( int )                                               */
/* ************************************************************************** */
#include "just_lib.h"

int	ft_is_prime(int nbr)
{
	int		i;

	i = 2;
	if (nbr <= 1)
		return (0);
	while (i < nbr && i > 0)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nbr)
{
	if (nbr <= 2)
		return (2);
	while (!ft_is_prime(nbr))
		nbr++;
	return (nbr);
}

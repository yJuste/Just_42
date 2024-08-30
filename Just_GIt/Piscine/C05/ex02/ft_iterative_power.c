/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_iterative_power(int nbr, int power)
{
	size_t		i;
	int			res;

	i = 0;
	res = 1;
	if (power < 0)
		return (0);
	while (i < power)
	{
		res = res * nbr;
		i++;
	}
	return (res);
}

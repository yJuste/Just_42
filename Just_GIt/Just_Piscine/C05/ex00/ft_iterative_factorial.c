/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
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

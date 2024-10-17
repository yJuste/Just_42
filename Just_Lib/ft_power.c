/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Returns the power of an num.                                           */
/*   • Prototype:   INT ( int, int )                                          */
/* ************************************************************************** */

// Iterative function

int	ft_iterative_power(int nbr, int power)
{
	int		i;
	int		res;

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

// Recursive function

int	ft_power(int nbr, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power >= 1)
		return (nbr * ft_power(nbr, power - 1));
	return (nbr);
}

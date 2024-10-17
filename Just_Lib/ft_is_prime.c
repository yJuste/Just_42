/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Returns 1 if prime.                                                    */
/*   • Prototype:   INT ( int )                                               */
/* ************************************************************************** */

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

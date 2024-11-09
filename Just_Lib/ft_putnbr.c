/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Displays a num.                                                        */
/*   • Prototype:   VOID ( int )                                              */
/*        -> write                                                            */
/* ************************************************************************** */
#include "just_lib.h"

void	ft_putnbr(int nbr)
{
	char		c;

	c = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
}

// mini ft_putnbr

void	ft_putnbr_mini(int nbr)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr / 10 > 0)
		ft_putnbr_mini(nbr / 10);
	ft_putchar(nbr % 10 + '0');
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Displays a num in a base.                                              */
/*   • Prototype:   VOID ( int, char * )                                      */
/*        -> write, size_t                                                    */
/* ************************************************************************** */
#include "just_lib.h"

void	ft_putnbr_base(int nbr, char *base)
{
	size_t		nb;

	nb = nbr;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base);
		ft_putnbr_base(nb % ft_strlen(base), base);
	}
	else
		ft_putchar(base[nb]);
	return ;
}

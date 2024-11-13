/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Displays the 2nd combinaison.                                          */
/*   • Prototype:   VOID ( void )                                             */
/*        -> write                                                            */
/* ************************************************************************** */
#include "../just_lib.h"

void	ft_dual_digit(int nb)
{
	ft_putchar(nb / 10 + '0');
	ft_putchar(nb % 10 + '0');
}

void	ft_print_comb2(void)
{
	int		i;
	int		j;

	i = 0;
	while (i < 99)
	{
		j = i + 1;
		while (j < 100)
		{
			ft_dual_digit(i);
			ft_putchar(' ');
			ft_dual_digit(j);
			if (i != 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			j++;
		}
		i++;
	}
}

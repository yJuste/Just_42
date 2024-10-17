/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dual_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Displays a num up to 2 digits.                                         */
/*   • Prototype:   VOID ( int )                                              */
/*        -> write                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_dual_digit(int nbr);
void	ft_putchar(char c);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_dual_digit(int nbr)
{
	ft_putchar(nbr / 10 + '0');
	ft_putchar(nbr % 10 + '0');
}

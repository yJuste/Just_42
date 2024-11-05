/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Rush_id : 2                                                            */
/*   • Displays :                                                             */
/*     ABBA                                                                   */
/*     B  B                                                                   */
/*     B  B                                                                   */
/*     CBBC                                                                   */
/*      -> ft_putchar                                                         */
/* ************************************************************************** */
#include "main.h"

// ----------------------------PROTOTYPE------------------------------
void	ft_rush02(int x, int y);
int		ft_print_corner02(int xi, int yi, int maxX, int maxY);
int		ft_print_edge02(int xi, int yi, int maxX, int maxY);
// -------------------------------------------------------------------

void	ft_rush02(int x, int y)
{
	int	xi;
	int	yi;

	yi = 0;
	while (yi < y)
	{
		xi = 0;
		while (xi < x)
		{
			if (ft_print_corner02(xi, yi, x - 1, y - 1) == 0)
			{
				if (ft_print_edge02(xi, yi, x - 1, y - 1) == 0)
					ft_putchar(' ');
			}
			xi++;
		}
		ft_putchar('\n');
		yi++;
	}
}

int	ft_print_corner02(int xi, int yi, int maxX, int maxY)
{
	if ((yi == 0 && xi == 0) || (yi == 0 && xi == maxX))
	{
		ft_putchar('A');
		return (1);
	}
	if ((yi == maxY && xi == 0) || (yi == maxY && xi == maxX))
	{
		ft_putchar('C');
		return (1);
	}
	return (0);
}

int	ft_print_edge02(int xi, int yi, int maxX, int maxY)
{
	if (xi == 0 || xi == maxX)
	{
		ft_putchar('B');
		return (1);
	}
	if (yi == 0 || yi == maxY)
	{
		ft_putchar('B');
		return (1);
	}
	return (0);
}

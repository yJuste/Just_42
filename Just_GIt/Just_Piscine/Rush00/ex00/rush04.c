/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Rush_id : 4                                                            */
/*   • Displays :                                                             */
/*     ABBC                                                                   */
/*     B  B                                                                   */
/*     B  B                                                                   */
/*     CBBA                                                                   */
/*      -> ft_putchar                                                         */
/* ************************************************************************** */
#include "main.h"

// --------------------------PROTOTYPE-----------------------------
void	rush04(int x, int y);
int		print_corner04(int xi, int yi, int maxX, int maxY);
int		print_edge04(int xi, int yi, int maxX, int maxY);
// ----------------------------------------------------------------

void	rush04(int x, int y)
{
	int	xi;
	int	yi;

	yi = 0;
	while (yi < y)
	{
		xi = 0;
		while (xi < x)
		{
			if (print_corner04(xi, yi, x - 1, y - 1) == 0)
			{
				if (print_edge04(xi, yi, x - 1, y - 1) == 0)
					ft_putchar(' ');
			}
			xi++;
		}
		ft_putchar('\n');
		yi++;
	}
}

int	print_corner04(int xi, int yi, int maxX, int maxY)
{
	if (xi == 0 && yi == 0)
	{
		ft_putchar('A');
		return (1);
	}
	if (xi == maxX && yi == maxY && maxY != 0 && maxX != 0)
	{
		ft_putchar('A');
		return (1);
	}
	if ((xi == maxX && yi == 0) || (xi == 0 && yi == maxY))
	{
		ft_putchar('C');
		return (1);
	}
	return (0);
}

int	print_edge04(int xi, int yi, int maxX, int maxY)
{
	if (xi == 0 || xi == maxX || yi == 0 || yi == maxY)
	{
		ft_putchar('B');
		return (1);
	}
	return (0);
}

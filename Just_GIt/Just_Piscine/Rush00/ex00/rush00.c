/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

int	print_corner00(int xi, int yi, int maxX, int maxY)
{
	if ((yi == 0 && xi == 0) || (yi == 0 && xi == maxX))
	{
		ft_putchar('o');
		return (1);
	}
	if ((yi == maxY && xi == 0) || (yi == maxY && xi == maxX))
	{
		ft_putchar('o');
		return (1);
	}
	return (0);
}

int	print_edge00(int xi, int yi, int maxX, int maxY)
{
	if (xi == 0 || xi == maxX)
	{
		ft_putchar('|');
		return (1);
	}
	if (yi == 0 || yi == maxY)
	{
		ft_putchar('-');
		return (1);
	}
	return (0);
}

void	rush00(int x, int y)
{
	int	xi;
	int	yi;

	yi = 0;
	while (yi < y)
	{
		xi = 0;
		while (xi < x)
		{
			if (print_corner00(xi, yi, x - 1, y - 1) == 0)
			{
				if (print_edge00(xi, yi, x - 1, y - 1) == 0)
					ft_putchar(' ');
			}
			xi++;
		}
		ft_putchar('\n');
		yi++;
	}
}

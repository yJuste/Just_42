/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Rush_id : 3                                                            */
/*   • Displays :                                                             */
/*     ABBC                                                                   */
/*     B  B                                                                   */
/*     B  B                                                                   */
/*     ABBC                                                                   */
/*      -> ft_putchar                                                         */
/* ************************************************************************** */
#include "main.h"

// ----------PROTOTYPE----------
void	ft_rush03(int x, int y);
// -----------------------------

void	ft_rush03(int x, int y)
{
	int	abs;
	int	ord;

	ord = 1;
	while (ord <= y)
	{
		abs = 1;
		while (abs <= x)
		{
			if ((abs == 1 && ord == 1) || (abs == 1 && ord == y))
				ft_putchar('A');
			else if ((abs == x && ord == 1) || (abs == x && ord == y))
				ft_putchar('C');
			else if (ord == 1 || ord == y)
				ft_putchar('B');
			else if (abs == 1 || abs == x)
				ft_putchar('B');
			else
				ft_putchar(' ');
			abs++;
		}
		ft_putchar('\n');
		ord++;
	}
}

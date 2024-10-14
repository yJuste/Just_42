/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Displays a rectangle.                                                  */
/*   • ./a.out [rush_id] [x] [y]                                              */
/*      -> rush_id // [0 <= rush_id <= 4]                                     */
/*      -> x and y // [numbers in int. format]                                */
/*      -> ft_putchar, ft_putstr, ft_atoi                                     */
/* ************************************************************************** */
#include "main.h"

// ----------------PROTOTYPE-------------------
int		main(int argc, char **argv);
void	ft_run_rush(int rush_id, int x, int y);
// -------------------------------------------

int	main(int argc, char **argv)
{
	argc--;
	if (argc != 3)
	{
		ft_putstr(" Usage: ");
		ft_putstr(argv[0]);
		ft_putstr(" [rush_id] [x] [y]\n");
		return (1);
	}
	ft_run_rush(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]));
	return (0);
}

void	ft_run_rush(int rush_id, int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		ft_putstr("Invalid Argument, x & y limits: ]0;INT_MAX]\n");
		return ;
	}
	if (rush_id == 0)
		ft_rush00(x, y);
	else if (rush_id == 1)
		ft_rush01(x, y);
	else if (rush_id == 2)
		ft_rush02(x, y);
	else if (rush_id == 3)
		ft_rush03(x, y);
	else if (rush_id == 4)
		ft_rush04(x, y);
	else
		ft_putstr("Rush not found. [0-4]\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

void	run_rush(int rush_id, int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		ft_putstr("Invalid Argument, x & y limits: ]0;INT_MAX]\n");
		return ;
	}
	if (rush_id == 0)
		rush00(x, y);
	else if (rush_id == 1)
		rush01(x, y);
	else if (rush_id == 2)
		rush02(x, y);
	else if (rush_id == 3)
		rush03(x, y);
	else if (rush_id == 4)
		rush04(x, y);
	else
	{
		ft_putstr("Rush not found.\n");
	}
}

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
	run_rush(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]));
	return (0);
}
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
/*   • Parse all grids and print the correct one.                             */
/*        -> ft_print, ft_putchar                                             */
/*        -> malloc, free                                                     */
/* ************************************************************************** */
#include "main.h"

// ---------------PROTOTYPE-------------------
int	ft_check_grid(t_grid *_grid, int size);
int	ft_parse_grid(t_grid *_grid, int size);

int	ft_print_grid(t_grid *_grid, int size);
// -------------------------------------------

int	ft_check_grid(t_grid *_grid, int size)
{
	if (ft_parse_grid(_grid, size))
		return (1);
	else
		return (0);
	ft_free_grid(_grid, size);
	return (0);
}

int	ft_parse_grid(t_grid *_grid, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!ft_check_column_top(_grid, i, _grid->tab[i], size))
			return (0);
		if (!ft_check_column_bottom(_grid, i, _grid->tab[size + i], size))
			return (0);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (!ft_check_row_left(_grid, i, _grid->tab[2 * size + i], size))
			return (0);
		if (!ft_check_row_right(_grid, i, _grid->tab[3 * size + i], size))
			return (0);
		i++;
	}
	return (1);
}

int	ft_print_grid(t_grid *_grid, int size)
{
	int	row;
	int	col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			ft_putchar(_grid->grid[row][col] + '0');
			if (col < size - 1)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
	return (0);
}

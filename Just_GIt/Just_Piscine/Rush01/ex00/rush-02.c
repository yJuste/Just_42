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
/*   • Generates all possible grids for a size.                               */
/*        -> malloc, free                                                     */
/* ************************************************************************** */
#include "main.h"

// ------------------------------PROTOTYPE---------------------------------
int	ft_grid(int tab[], int size);
int	ft_combination(t_grid *_grid, int size);
int	ft_fill_grid(t_grid *_grid, int row, int col, int *found);
int	ft_end_of_line(int *row, int *col, int size);
int	ft_is_valid(t_grid *_grid, int row, int col, int num);
// ------------------------------------------------------------------------

int	ft_grid(int tab[], int size)
{
	t_grid		_grid;

	_grid.grid = NULL;
	_grid.count = 0;
	_grid.tab = tab;
	_grid.size = size;
	if (ft_combination(&_grid, size) == -1)
		return (-1);
	return (0);
}

//	---BONUS--- line 10 to 11
//	printf("Total number of grids for %dx%d: %d\n",
//	size, size, _grid->count);
int	ft_combination(t_grid *_grid, int size)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	_grid->grid = malloc(sizeof(int *) * size);
	while (i < size)
	{
		_grid->grid[i] = malloc(sizeof(int) * size);
		i++;
	}
	ft_fill_grid(_grid, 0, 0, &found);
	ft_free_grid(_grid, size);
	if (found == 0)
		return (-1);
	return (0);
}

//	---BONUS--- line 6 to 7
//	_grid->count++;
int	ft_fill_grid(t_grid *_grid, int row, int col, int *found)
{
	int	num;

	if (row == _grid->size - 1 && col == _grid->size)
	{
		if (ft_check_grid(_grid, _grid->size) == 1)
		{
			ft_print_grid(_grid, _grid->size);
			*found = 1;
		}
		return (0);
	}
	if (ft_end_of_line(&row, &col, _grid->size))
		return (ft_fill_grid(_grid, row, col, found));
	num = 1;
	while (num <= _grid->size)
	{
		if (ft_is_valid(_grid, row, col, num))
		{
			_grid->grid[row][col] = num;
			ft_fill_grid(_grid, row, col + 1, found);
			_grid->grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int	ft_end_of_line(int *row, int *col, int size)
{
	if (*col == size)
	{
		(*row)++;
		*col = 0;
		return (1);
	}
	return (0);
}

int	ft_is_valid(t_grid *_grid, int row, int col, int num)
{
	int	x;

	x = 0;
	while (x < _grid->size)
	{
		if (_grid->grid[row][x] == num || _grid->grid[x][col] == num)
			return (0);
		x++;
	}
	return (1);
}

/*	--------------------Bonus-----------------------
	--- displays the number of possible grids    ---
	--- for a size of NxN in the skycraper game. ---
	------------------------------------------------
*/

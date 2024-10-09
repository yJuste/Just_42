/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • The skycraper algorithm.                                               */
/* ************************************************************************** */
#include "main.h"

// -------------------------------PROTOTYPE-----------------------------------
int	ft_check_column_top(t_grid *_grid, int col, int expected, int size);
int	ft_check_column_bottom(t_grid *_grid, int col, int expected, int size);
int	ft_check_row_left(t_grid *_grid, int row, int expected, int size);
int	ft_check_row_right(t_grid *_grid, int row, int expected, int size);
// ---------------------------------------------------------------------------

int	ft_check_column_top(t_grid *_grid, int col, int expected, int size)
{
	int	count;
	int	max_height;
	int	i;

	count = 1;
	max_height = _grid->grid[0][col];
	i = 1;
	while (i < size)
	{
		if (_grid->grid[i][col] > max_height)
		{
			count++;
			max_height = _grid->grid[i][col];
		}
		i++;
	}
	return (count == expected);
}

int	ft_check_column_bottom(t_grid *_grid, int col, int expected, int size)
{
	int	count;
	int	max_height;
	int	i;

	count = 1;
	max_height = _grid->grid[size - 1][col];
	i = size - 2;
	while (i >= 0)
	{
		if (_grid->grid[i][col] > max_height)
		{
			count++;
			max_height = _grid->grid[i][col];
		}
		i--;
	}
	return (count == expected);
}

int	ft_check_row_left(t_grid *_grid, int row, int expected, int size)
{
	int	count;
	int	max_height;
	int	i;

	count = 1;
	max_height = _grid->grid[row][0];
	i = 1;
	while (i < size)
	{
		if (_grid->grid[row][i] > max_height)
		{
			count++;
			max_height = _grid->grid[row][i];
		}
		i++;
	}
	return (count == expected);
}

int	ft_check_row_right(t_grid *_grid, int row, int expected, int size)
{
	int	count;
	int	max_height;
	int	i;

	count = 1;
	max_height = _grid->grid[row][size - 1];
	i = size - 2;
	while (i >= 0)
	{
		if (_grid->grid[row][i] > max_height)
		{
			count++;
			max_height = _grid->grid[row][i];
		}
		i--;
	}
	return (count == expected);
}

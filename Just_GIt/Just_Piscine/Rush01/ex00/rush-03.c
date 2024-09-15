/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

void	ft_combination(int size);
void	ft_fill_grid(int **grid, int row, int col, int *count, int size);
int	ft_is_valid(int **grid, int row, int col, int num, int size);
void	ft_print_grid(int **grid, int size);
int	main(void);

void	ft_print_grid(int **grid, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			printf("%d ", grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	ft_putstr("-------------------------------\n");
}

int	ft_is_valid(int **grid, int row, int col, int num, int size)
{
	int	x;
	
	x = 0;
	while (x < size)
	{
		if (grid[row][x] == num || grid[x][col] == num)
			return (0);
		x++;
	}
	return (1);
}

void	ft_fill_grid(int **grid, int row, int col, int *count, int size)
{
	int	num;

	if (row == size - 1 && col == size)
	{
		(*count)++;
		return ;
	}
	if (col == size)
	{
		row++;
		col = 0;
	}
	num = 1;
	while (num <= size)
	{
		if (ft_is_valid(grid, row, col, num, size))
		{
			grid[row][col] = num;
			ft_fill_grid(grid, row, col + 1, count, size);
			grid[row][col] = 0;
		}
		num++;
	}
}

void	ft_combination(int size)
{
	int	**grid;
	int	count;
	int	i;

	count = 0;
	i = 0;
	grid = malloc(size * sizeof(int *));
	while (i < size)
	{
		grid[i] = malloc(size * sizeof(int));
		i++;
	}
	ft_fill_grid(grid, 0, 0, &count, size);
	printf("Nombre total de solutions pour une grille %dx%d: %d\n", size, size, count);
	while (i < size)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	return ;
}

int	main(void)
{
	int	size;
	
	size = 4;
	if (size >= 1 && size <= 9)
		ft_combination(size);
	return (0);
}

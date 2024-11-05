/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

// 724 possibilités

// Un appel récursif met en pause la fonction en cours. C'est pour cela que
// si tu appelles la meme et que rien n'est bon, tu reviens en "arriere".
// C'est plutot faux car il suit tout de meme un seul flux mais se met
// en pause en fait en attedant la nouvelle fonction qui se lance.
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_solution(int *board)
{
	int	i;

	i = 0;
	if (!board)
		return ;
	while (i < 10)
	{
		ft_putchar(board[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

int	ft_is_safe(int *board, int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row
			|| board[i] - i == row - col
			|| board[i] + i == row + col)
			return (0);
		i++;
	}
	return (1);
}

void	ft_solve(int *board, int col, int *count)
{
	int	row;

	row = 0;
	if (col == 10)
	{
		ft_print_solution(board);
		(*count)++;
		return ;
	}
	while (row < 10)
	{
		if (ft_is_safe(board, row, col))
		{
			board[col] = row;
			ft_solve(board, col + 1, count);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	ft_solve(board, 0, &count);
	return (count);
}

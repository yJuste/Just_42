/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int *board, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(board[i] + '0');
		i++;
	}
	if (board[0] != 10 - n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_solve(int *board, int n, int start, int depth)
{
	int	i;

	i = start;
	if (depth == n)
	{
		ft_print(board, n);
		return ;
	}
	while (i < 10)
	{
		board[depth] = i;
		ft_solve(board, n, i + 1, depth + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	board[10];

	if (n <= 0 || n >= 10)
		return ;
	ft_solve(board, n, 0, 0);
	return ;
}

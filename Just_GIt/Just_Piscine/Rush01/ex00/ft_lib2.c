/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Second Library.                                                        */
/* ************************************************************************** */
#include "main.h"

// ----------------PROTOTYPE------------------
int		ft_error(void);
void	ft_free_grid(t_grid *_grid, int size);
void	ft_free_tab(int *tab, int size);
// -------------------------------------------

int	ft_error(void)
{
	ft_putstr("Error\n");
	return (-1);
}

void	ft_free_grid(t_grid *_grid, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(_grid->grid[i]);
		i++;
	}
	free(_grid->grid);
	free(_grid->tab);
}

void	ft_free_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab);
		i++;
	}
}

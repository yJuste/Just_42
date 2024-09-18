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
#include "main.h"

int		ft_error(void);
void	ft_free_grid(t_grid *_grid, int size);

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

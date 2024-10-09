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
/*   • Resolve the skycraper game.                                            */
/*   • ./a.out ([ size ]) [ clues ]                                           */
/*        -> size    [ 1 <= size <= 9 ]                                       */
/*        -> clues   [ top, bottom, left, right ]                             */
/*        -> ft_error                                                         */
/* ************************************************************************** */
#include "main.h"

// -------------PROTOTYPE----------------
int	main(int argc, char **argv);
int	ft_init_2(char **argv, int size);
int	ft_init_3(char **argv, int size);
// --------------------------------------

int	main(int argc, char **argv)
{
	int	size;

	size = 0;
	if (argc == 2)
		ft_init_2(argv, size);
	else if (argc == 3)
		ft_init_3(argv, size);
	else
		return (ft_error());
	return (0);
}

int	ft_init_2(char **argv, int size)
{
	size = 4;
	if (ft_format(argv[1], size) == -1)
		return (ft_error());
	return (0);
}

int	ft_init_3(char **argv, int size)
{
	size = ft_dimensions(argv[1]);
	if (size == -1)
		return (ft_error());
	if (ft_format(argv[2], size) == -1)
		return (ft_error());
	return (0);
}

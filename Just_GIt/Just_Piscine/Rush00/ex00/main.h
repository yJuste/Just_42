/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Displays a rectangle.                                                  */
/*   • ./a.out [rush_id] [x] [y]                                              */
/*      -> rush_id // [0 <= rush_id <= 4]                                     */
/*      -> x and y // [numbers in int. format]                                */
/*      -> ft_putchar, ft_putstr, ft_atoi                                     */
/* ************************************************************************** */
#ifndef MAIN_H
# define MAIN_H

# include <unistd.h> 

// ft_lib.c

int		ft_isspace(char c);
int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);

// main.c

int		main(int argc, char **argv);
void	ft_run_rush(int rush_id, int x, int y);

// rush-00.c

void	ft_rush00(int x, int y);
int		ft_print_corner00(int xi, int yi, int maxX, int maxY);
int		ft_print_edge00(int xi, int yi, int maxX, int maxY);

// rush-01.c

void	ft_rush01(int x, int y);
int		ft_print_corner01(int xi, int yi, int maxX, int maxY);
int		ft_print_edge01(int xi, int yi, int maxX, int maxY);

// rush-02.c

void	ft_rush02(int x, int y);
int		ft_print_corner02(int xi, int yi, int maxX, int maxY);
int		ft_print_edge02(int xi, int yi, int maxX, int maxY);

// rush-03.c

void	ft_rush03(int x, int y);

// rush-04.c

void	ft_rush04(int x, int y);
int		ft_print_corner04(int xi, int yi, int maxX, int maxY);
int		ft_print_edge04(int xi, int yi, int maxX, int maxY);

#endif

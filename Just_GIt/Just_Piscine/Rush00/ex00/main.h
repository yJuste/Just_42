/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
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
void	run_rush(int rush_id, int x, int y);

// rush00.c

void	rush00(int x, int y);
int		print_corner00(int xi, int yi, int maxX, int maxY);
int		print_edge00(int xi, int yi, int maxX, int maxY);

// rush01.c

void	rush01(int x, int y);
int		print_corner01(int xi, int yi, int maxX, int maxY);
int		print_edge01(int xi, int yi, int maxX, int maxY);

// rush02.c

void	rush02(int x, int y);
int		print_corner02(int xi, int yi, int maxX, int maxY);
int		print_edge02(int xi, int yi, int maxX, int maxY);

// rush03.c

void	rush03(int x, int y);

// rush04.c

void	rush04(int x, int y);
int		print_corner04(int xi, int yi, int maxX, int maxY);
int		print_edge04(int xi, int yi, int maxX, int maxY);

#endif

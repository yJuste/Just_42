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
/*   • Resolve the skycraper game.                                            */
/*   • This is the header for the main.c                                      */
/* ************************************************************************** */
#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// Structure

typedef struct s_grid
{
	int		**grid;
	int		count;
	int		*tab;
	int		size;
}	t_grid;

// ft_lib.c

int		ft_strlen(char *str);
int		ft_isdigit(int c);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	ft_putchar(char c);

// ft_lib2.c

int		ft_error(void);
void	ft_free_grid(t_grid *_grid, int size);
void	ft_free_tab(int *tab, int size);

// main.c

int		main(int argc, char **argv);
int		ft_init_2(char **argv, int size);
int		ft_init_3(char **argv, int size);

// rush-01.c

int		ft_dimensions(char *str);
int		ft_format(char *str, int size);
int		ft_check_format(char *str, int *count);
int		*ft_create_format(char *str, int *tab, int size);
void	ft_print_format(int *tab, int size);

// rush-02.c

int		ft_grid(int tab[], int size);
int		ft_combination(t_grid *_grid, int size);
int		ft_fill_grid(t_grid *_grid, int row, int col, int *found);
int		ft_end_of_line(int *row, int *col, int size);
int		ft_is_valid(t_grid *_grid, int row, int col, int num);

// rush-03.c

int		ft_check_grid(t_grid *_grid, int size);
int		ft_parse_grid(t_grid *_grid, int size);
int		ft_print_grid(t_grid *_grid, int size);

// rush-04.c

int		ft_check_column_top(t_grid *_grid, int col, int expected, int size);
int		ft_check_column_bottom(t_grid *_grid, int col, int expected, int size);
int		ft_check_row_left(t_grid *_grid, int row, int expected, int size);
int		ft_check_row_right(t_grid *_grid, int row, int expected, int size);

#endif

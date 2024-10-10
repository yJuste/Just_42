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
/*   • Converts a number into its literal value.                              */
/*   • ./a.out ([ dictionnary ]) [ number ]                                   */
/*      -> dictionnary   [ en ]                                               */
/*      -> number        [ -10^39 < x < +10^39 ]                              */
/*        -> ft_error, ft_strdup, ft_strtolower, ft_strcmp                    */
/*        -> free                                                             */
/* ************************************************************************** */
#ifndef MAIN_H
# define MAIN_H

// Standard Libraries

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

// Buffer

# ifndef BUFFER_SIZE
#  define BUFFER_SEP 90 // BUFFER_MIN = 87
# endif

// Structures

typedef struct s_num
{
	int		filename_flg;
	int		sign;
	int		sign_flg;
	int		index;
	int		fd;
	int		flg;
	char	*filename;
	char	*nb;
	char	*final_nb;
	char	*tmp;
}	t_num;

typedef struct s_sep
{
	int		xi;
	int		xj;
	int		xnb;
	int		len;
	int		len_total;
	int		cooldown;
}	t_sep;

// ft_get_next_line.c

char	*ft_get_next_line(int fd);
char	*ft_read_f_save(int fd, char *f_save);
char	*ft_get_line(char *f_save);
char	*ft_next_line(char *f_save);

//	----------MY LIBRARY----------

// ft_lib.c

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_free_str(char **str);
int		ft_strlen(const char *str);
int		ft_error(int error);

// ft_lib2.c

int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_tolower(int c);
char	*ft_strtolower(char *str);

// ft_lib3.c

char	*ft_strdup(const char *src);
void	*ft_malloc(int size);
void	*ft_calloc(int size_of, int size);

// ft_lib4.c

int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

//	----------MY CODE----------

// main.c

int		main(int argc, char **argv);
int		ft_get_args(int argc, char **argv, char **filename, char **param);
int		ft_init(char **filename, char *nb);
void	ft_get_dict(char **filename, int *filename_flg);
void	ft_select_dict(char **filename, char *lw_filename,
			char *dict, int *filename_flg);

// rush-01.c

int		ft_check_format(char *nb, char **f_nb, int *sign);
int		ft_check_sign(char *nb, int *sign);
int		ft_check_number(char *nb);
int		ft_trim_space(char *nb, char **f_nb, int f_sign);
char	*ft_trim_zero(char *nb);

// rush-02.c

int		ft_dict(char *filename, char *nb, int *sign, int *filename_flg);
int		ft_dict_init(t_num *_num, char ***sub_numbers);
int		ft_print_equivalent(t_num *_num, char **sub_numbers, char *line);
void	ft_append_sign(t_num *_num);
void	ft_print_final_nb(t_num *_num);

// rush-03.c

int		ft_equivalent_init(t_num *_num, char **line);
int		ft_open_fd(t_num *_num);
void	ft_flg(t_num *_num, char **line);
void	ft_add_tiret(t_num *_num);
int		ft_take_number_dict(t_num *_num, char **line);

// rush-04.c

void	ft_correct_comp(t_num *_num, char **line);
int		ft_error_line(char **line);
void	ft_parse_next_line(t_num *_num, char **line);
void	ft_close_fd(t_num *_num);
int		ft_print_result(t_num *_num, char **line);

// rush-05.c

int		ft_check_line_format(char *line);
int		ft_check_line_format_2(char *line, int i);
char	*ft_number_dict(char *line);
int		ft_len_dict_number(char *line);

// rush-06.c

void	ft_equivalent(t_num *_num, char *line);
void	ft_join_equivalent(t_num *_num, char **str);
void	ft_tiret(t_num *_num);

char	*ft_read(const char *message, const char *default_vle);
char	*ft_read_get_default(const char *default_vle);

//	-----ALGORITHM FOR ENGLISH-----

// rush-07.c

void	ft_separate(char ***separated, char *nb);
void	ft_alloc_str(char ***str);
void	ft_trio(t_sep *_sep, char **str, char *nb);
void	ft_get_2_digits(t_sep *_sep, char **str, char *nb);
void	ft_get_2_digits_next(t_sep *_sep, char **str, char *nb);

// rush-08.c

void	ft_get_digit(t_sep *_sep, char **str, char *nb);
void	ft_get_100(t_sep *_sep, char **str, char *nb);
void	ft_get_power(t_sep *_sep, char **str);
void	ft_get_power_2(t_sep *_sep, char **str, int *flg);
void	ft_get_power_3(t_sep *_sep, char **str, int *flg);

#endif

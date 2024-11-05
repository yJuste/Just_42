/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_TAIL_H
# define FT_TAIL_H

// Standard Libraries

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <limits.h>

// Structure

typedef struct s_range
{
	int			flg;
	ssize_t		size;
	ssize_t		k;
	ssize_t		m;
	ssize_t		g;
	ssize_t		t;
}	t_range;

// ft_tail.c

int		main(int argc, char **argv);
int		ft_lrange(int argc, char **argv);
int		ft_lrange_2(t_range *_range, int argc, char **argv);
int		ft_lrange_3(t_range *_range, char **argv);
int		ft_init(t_range *_range, int argc, char **argv);

// ft_tail_2.c

void	ft_tail(t_range *_range, int fd, char *arg);
int		ft_echo(char **argv);
int		ft_read_file(char **content);

void	*ft_malloc(int size);
void	*ft_memcpy(void *dst, const void *src, size_t n);

// ft_lib_tail.c

int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
int		ft_tolower(int c);
int		ft_isdigit(int c);
size_t	ft_strlen(char *str);

// ft_error_tail.c

void	ft_header(int argc, char *filename);
void	ft_tail_error(int err, char *filename);
int		ft_error_flg(t_range *_range, char **argv);
int		ft_error_read(int b_read, char **content);

#endif

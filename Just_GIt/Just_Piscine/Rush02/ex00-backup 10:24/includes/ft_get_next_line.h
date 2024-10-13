/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Read a line from a file.                                               */
/*        -> ft_strchr, ft_strlen, ft_strjoin                                 */
/*        -> malloc, free, buffer, read                                       */
/* ************************************************************************** */
#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

// Buffer

# ifndef BUFFER_SIZE
#  define BUFFER_GET_LINE 60 // BUFFER_MIN = 50 | BUFFER_MAX = 100
# endif

// ft_get_next_line.c

char		*ft_get_next_line(int fd);
char		*ft_read_f_save(int fd, char *f_save);
char		*ft_get_line(char *f_save);
char		*ft_next_line(char *f_save);

// In other libraries

int			ft_strlen(const char *str);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *s1, char *s2);

#endif

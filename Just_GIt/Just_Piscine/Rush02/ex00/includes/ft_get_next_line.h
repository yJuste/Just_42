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
#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

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

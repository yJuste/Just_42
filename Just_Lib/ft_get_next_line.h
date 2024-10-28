/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Get each line from a file.                                             */
/*   • Prototype:   CHAR * ( int )                                            */
/*        -> malloc, size_t, static                                           */
/* ************************************************************************** */
#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

// Standard Libraries

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

// Buffers

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 60
# endif

# ifndef MAX_LINE
#  define MAX_LINE 50000
# endif

// Structure

typedef struct s_lne
{
	char	buffer[BUFFER_SIZE];
	int		read_bf;
	int		pos_bf;
	int		fd;
}	t_lne;

// ft_get_next_line.c

char	*ft_get_next_line(int fd);
int		ft_get_line(t_lne *_lne, char *line, int *i);
char	*ft_strdup(const char *src);

#endif

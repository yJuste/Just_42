/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Get each line from a file.                                             */
/*   • Prototype:   CHAR * ( int )                                            */
/*        -> static                                                           */
/* ************************************************************************** */
#include "just_lib.h"
#include "ft_get_next_line.h"

// don't forget to free the line !

char	*get_next_line(int fd)
{
	static t_buf	buf[FD_MAX];
	char			line[5000];
	int				i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_MAX)
		return (NULL);
	while (1)
	{
		if (buf[fd].buf_pos >= buf[fd].buf_read)
		{
			buf[fd].buf_read = read(fd, buf[fd].buffer, BUFFER_SIZE);
			buf[fd].buf_pos = 0;
			if (buf[fd].buf_read <= 0)
				break ;
		}
		line[i++] = buf[fd].buffer[buf[fd].buf_pos++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

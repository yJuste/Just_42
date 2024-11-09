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
/*        -> malloc, size_t, static                                           */
/* ************************************************************************** */
#include "just_lib.h"
#include "ft_get_next_line.h"

// don't forget to free the line !
// get_next_line sur la heap

char	*ft_get_next_line(int fd)
{
	static t_lne	_lne;
	char			line[MAX_LINE];
	int				i;

	i = 0;
	_lne.fd = fd;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_get_line(&_lne, line, &i) == -1)
		return (NULL);
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

static int	ft_get_line(t_lne *_lne, char *line, int *i)
{
	int		flg;

	flg = 0;
	while (flg < MAX_LINE)
	{
		if (_lne->pos_bf >= _lne->read_bf)
		{
			_lne->read_bf = read(_lne->fd, _lne->buffer, BUFFER_SIZE);
			_lne->pos_bf = 0;
			if (_lne->read_bf <= 0)
				break ;
		}
		if (line[*i] == '\n')
			break ;
		line[*i] = _lne->buffer[_lne->pos_bf++];
		(*i)++;
		flg++;
	}
	if (flg == MAX_LINE)
		return (-1);
	return (0);
}

/*	ft_get_next_line_mini sur la stack

char	*get_next_line_mini(int fd)
{
	static char	buffer[60];
	static int	buf_read;
	static int 	buf_pos;
	char		line[50000];
	int			i;

	i = 0;
	if (fd < 0)
		return (NULL);
	while (1)
	{
		if (buf_pos >= buf_read)
		{
			buf_read = read(fd, buffer, 60);
			buf_pos = 0;
			if (buf_read <= 0)
				break ;
		}
		if (line[i] == '\n')
			break ;
		line[i++] = buffer[buf_pos++];
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}
*/

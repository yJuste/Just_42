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
#include "ft_get_next_line.h"

// don't forget to free the line !

char	*ft_get_next_line(int fd);
int		ft_get_line(t_lne *_lne, char *line, int *i);
char	*ft_strdup(const char *src);

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

int	ft_get_line(t_lne *_lne, char *line, int *i)
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

char	*ft_strdup(const char *src)
{
	char		*dest;
	size_t		i;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

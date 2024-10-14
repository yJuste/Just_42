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
/*   • Read a line from a file.                                               */
/*        -> ft_strchr, ft_strlen, ft_strjoin                                 */
/*        -> malloc, free, buffer, read                                       */
/* ************************************************************************** */
#include "../includes/main.h"
#include "../includes/ft_get_next_line.h"

// ---------------PROTOTYPE-------------------
char	*ft_get_next_line(int fd);
char	*ft_read_f_save(int fd, char *f_save);
char	*ft_get_line(char *f_save);
char	*ft_next_line(char *f_save);
// -------------------------------------------

char	*ft_get_next_line(int fd)
{
	char		*line;
	static char	*f_save;

	if (fd < 0 || BUFFER_GET_LINE <= 0)
		return (0);
	f_save = ft_read_f_save(fd, f_save);
	if (!f_save)
		return (NULL);
	line = ft_get_line(f_save);
	f_save = ft_next_line(f_save);
	if (!line || !*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*ft_read_f_save(int fd, char *f_save)
{
	char	*buff;
	int		read_bytes;

	buff = malloc(sizeof(char) * (BUFFER_GET_LINE + 1));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(f_save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_GET_LINE);
		if (read_bytes == -1)
		{
			free(buff);
			free(f_save);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		f_save = ft_strjoin(f_save, buff);
	}
	free(buff);
	return (f_save);
}

char	*ft_get_line(char *f_save)
{
	char	*str;
	int		i;

	i = 0;
	while (f_save[i] != '\0' && f_save[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (f_save[i] != '\0' && f_save[i] != '\n')
	{
		str[i] = f_save[i];
		i++;
	}
	if (f_save[i] == '\n')
	{
		str[i] = f_save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_next_line(char *f_save)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (f_save[i] && f_save[i] != '\n')
		i++;
	if (!f_save[i])
	{
		free(f_save);
		return (NULL);
	}
	str = malloc(sizeof(char) * ft_strlen(f_save) - i + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (f_save[i])
		str[j++] = f_save[i++];
	str[j] = '\0';
	free(f_save);
	return (str);
}

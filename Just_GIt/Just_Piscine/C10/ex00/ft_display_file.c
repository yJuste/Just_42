/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>

int		main(int argc, char **argv);
int		ft_display_file(char *file);
int		ft_error(int err);
int		ft_close(int fd);

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (ft_error(-1));
	if (argc == 2)
	{
		if (ft_display_file(argv[1]) == -1)
			return (ft_error(-2));
	}
	if (argc > 2)
		return (ft_error(-3));
	return (0);
}

int	ft_display_file(char *file)
{
	int			fd;
	ssize_t		b_read;
	ssize_t		b_written;
	char		buffer[500];

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	b_read = read(fd, buffer, sizeof(buffer));
	while (b_read > 0)
	{
		b_written = write(1, buffer, b_read);
		if (b_written < 0)
			return (ft_close(fd));
		b_read = read(fd, buffer, sizeof(buffer));
	}
	if (b_read < 0)
		return (ft_close(fd));
	close(fd);
	return (0);
}

int	ft_error(int err)
{
	if (err == -1)
	{
		write(1, "File name missing.\n", 19);
		return (err);
	}
	else if (err == -2)
	{
		write(1, "Cannot read file.\n", 19);
		return (err);
	}
	else if (err == -3)
	{
		write(1, "Too many arguments.\n", 20);
		return (err);
	}
	return (0);
}

int	ft_close(int fd)
{
	close(fd);
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int		main(int argc, char **argv);
int		ft_init(int argc, char **argv);
void	ft_display_file(int fd, char *filename);
void	ft_cat_error(char *filename);
int		ft_strlen(char *str);

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_display_file(0, "");
	else
		if (ft_init(argc, argv) == -1)
			return (-1);
	return (0);
}

int	ft_init(int argc, char **argv)
{
	int		flg;
	int		fd;
	int		i;

	flg = 0;
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			ft_cat_error(argv[i]);
			flg = -1;
		}
		else
		{
			ft_display_file(fd, argv[i]);
			close(fd);
		}
		i++;
	}
	return (flg);
}

void	ft_display_file(int fd, char *filename)
{
	char		buffer[29500];
	ssize_t		b_read;
	ssize_t		b_written;

	b_read = read(fd, buffer, sizeof(buffer));
	while (b_read > 0)
	{
		b_written = write(1, buffer, b_read);
		if (b_written < 0)
		{
			ft_cat_error(filename);
			return ;
		}
		b_read = read(fd, buffer, sizeof(buffer));
	}
	if (b_read < 0)
	{
		ft_cat_error(filename);
		return ;
	}
	return ;
}

void	ft_cat_error(char *filename)
{
	write(2, "cat: ", 5);
	write(2, filename, ft_strlen(filename));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	return ;
}

int	ft_strlen(char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

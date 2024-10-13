/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_tail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./ft_tail.h"

// ----------------------PROTOTYPE-------------------------
void	ft_header(int argc, char *filename);
void	ft_tail_error(int err, char *filename);
int		ft_error_flg(t_range *_range, char **argv);
int		ft_error_read(int b_read, char **content);
// --------------------------------------------------------

void	ft_header(int argc, char *filename)
{
	if (argc >= 5)
	{
		write(1, "==> ", 4);
		write(1, filename, ft_strlen(filename));
		write(1, " <==\n", 5);
	}
	return ;
}

void	ft_tail_error(int err, char *filename)
{
	if (err == -1)
	{
		write(2, "tail: ", 6);
		write(2, filename, ft_strlen(filename));
		write(2, ": ", 2);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
	}
	else if (err == -2)
	{
		write(2, "tail: option requires an argument -- c\n", 39);
		write(2, "usage: tail [-F | -f | -r] [-q] ", 32);
		write(2, "[-b # | -c # | -n #] [file ...]\n", 32);
	}
	else if (err == -3 || err == -4)
	{
		write(2, "tail: illegal offset -- ", 24);
		write(2, filename, ft_strlen(filename));
		write(2, ": ", 2);
		if (err == -3)
			write(2, "Invalid argument", 16);
		else
			write(2, "Result too large", 17);
		write(2, "\n", 1);
	}
}

int	ft_error_flg(t_range *_range, char **argv)
{
	int	i;

	i = 0;
	while (ft_isdigit(argv[2][i]))
	{
		_range->flg = 1;
		i++;
	}
	if (_range->flg == 0)
	{
		ft_tail_error(-3, argv[2]);
		return (-1);
	}
	return (i);
}

int	ft_error_read(int b_read, char **content)
{
	if (b_read == -1)
	{
		free(*content);
		*content = NULL;
		return (-1);
	}
	return (0);
}

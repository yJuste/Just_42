/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./ft_tail.h"

// ----------------------PROTOTYPE-------------------------
int	main(int argc, char **argv);
int	ft_range(int argc, char **argv);
int	ft_range_2(t_range *_range, int argc, char **argv);
int	ft_range_3(t_range *_range, char **argv);
int	ft_init(t_range *_range, int argc, char **argv);
// --------------------------------------------------------

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_tail_error(-1, "");
		return (-1);
	}
	if (argc == 2)
	{
		ft_tail_error(-2, argv[1]);
		return (-1);
	}
	else
	{
		if (ft_strcmp(argv[1], "-c") != 0)
		{
			ft_tail_error(-2, "");
			return (-1);
		}
		if (ft_range(argc, argv) == -1)
			return (-1);
	}
	return (0);
}

int	ft_range(int argc, char **argv)
{
	int		i;
	t_range	_range;

	_range.size = 0;
	_range.flg = 0;
	i = ft_error_flg(&_range, argv);
	if (i == -1)
		return (-1);
	if (argv[2][i] != '\0')
	{
		if (ft_tolower(argv[2][i]) != 'k' &&
			ft_tolower(argv[2][i]) != 'm' &&
			ft_tolower(argv[2][i]) != 'g' &&
			ft_tolower(argv[2][i]) != 't')
		{
			ft_tail_error(-3, argv[2]);
			return (-1);
		}
	}
	if (ft_range_2(&_range, argc, argv) == -1)
		return (-1);
	return (0);
}

int	ft_range_2(t_range *_range, int argc, char **argv)
{
	if (ft_range_3(_range, argv) == -1)
		return (-1);
	if (argc == 3)
	{
		if (ft_echo(argv) == -1)
			return (-1);
	}
	else if (ft_init(_range, argc, argv) == -1)
		return (-1);
	return (0);
}

int	ft_range_3(t_range *_range, char **argv)
{
	int		i;

	i = 0;
	while (ft_isdigit(argv[2][i]))
		i++;
	_range->k = 1024;
	_range->m = 1048576;
	_range->g = 1073741824;
	_range->t = 1099511627776;
	_range->size = ft_atoi(argv[2]);
	if (ft_tolower(argv[2][i]) == 'k')
		_range->size *= _range->k;
	else if (ft_tolower(argv[2][i]) == 'm')
		_range->size *= _range->m;
	else if (ft_tolower(argv[2][i]) == 'g')
		_range->size *= _range->g;
	else if (ft_tolower(argv[2][i]) == 't')
		_range->size *= _range->t;
	if (_range->size < 0)
	{
		ft_tail_error(-4, argv[2]);
		return (-1);
	}
	return (0);
}

int	ft_init(t_range *_range, int argc, char **argv)
{
	int		flg;
	int		fd;
	int		i;

	i = 3;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			ft_tail_error(-1, argv[i]);
			flg = -1;
		}
		else
		{
			ft_header(argc, argv[i]);
			ft_tail(_range, fd, argv[i]);
			close(fd);
			if (i != argc - 1)
				write(1, "\n", 1);
		}
		i++;
	}
	return (flg);
}

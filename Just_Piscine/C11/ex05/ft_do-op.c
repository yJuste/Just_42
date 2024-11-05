/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do-op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_do_op.h"

int	main(int argc, char **argv);
int	ft_do_op(char **argv);
int	ft_op(char *str);

int	main(int argc, char **argv)
{
	int	code;

	code = 0;
	if (argc == 4)
	{
		code = ft_do_op(argv);
		if (code == -1)
		{
			write(1, "0\n", 2);
			return (-1);
		}
		if (code == -2 || code == -3)
			return (code);
	}
	return (code);
}

int	ft_do_op(char **argv)
{
	int	nb1;
	int	nb2;
	int	(*operator[5])(int, int);
	int	op;
	int	res;

	nb1 = ft_atoi(argv[1]);
	nb2 = ft_atoi(argv[3]);
	operator[0] = ft_add;
	operator[1] = ft_sub;
	operator[2] = ft_mult;
	operator[3] = ft_div;
	operator[4] = ft_mod;
	op = ft_op(argv[2]);
	if (op == -1)
		return (-1);
	if (op == 3 && nb2 == 0)
		return (ft_error(-2));
	if (op == 4 && nb2 == 0)
		return (ft_error(-3));
	res = operator[op](nb1, nb2);
	ft_putnbr(res);
	write(1, "\n", 1);
	return (0);
}

int	ft_op(char *str)
{
	if (ft_strcmp(str, "+") == 0)
		return (0);
	else if (ft_strcmp(str, "-") == 0)
		return (1);
	else if (ft_strcmp(str, "*") == 0)
		return (2);
	else if (ft_strcmp(str, "/") == 0)
		return (3);
	else if (ft_strcmp(str, "%") == 0)
		return (4);
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_do_op.h"

int	ft_add(int a, int b);
int	ft_sub(int a, int b);
int	ft_div(int a, int b);
int	ft_mult(int a, int b);
int	ft_mod(int a, int b);

int	ft_add(int a, int b)
{
	return (a + b);
}

int	ft_sub(int a, int b)
{
	return (a - b);
}

int	ft_mult(int a, int b)
{
	return (a * b);
}

int	ft_div(int a, int b)
{
	if (b != 0)
		return (a / b);
	else
		return (0);
}

int	ft_mod(int a, int b)
{
	if (b != 0)
		return (a % b);
	else
		return (0);
}

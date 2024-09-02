/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hundreds.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struc.h"
#include "../libs/lib_string.h"
#include "../libs/lib_arg1.h"

void	convert_hundreds(int number, char *buffer, size_t *len)
{
	int	hundred;
	int	rest;

	if (number >= 100)
	{
		hundred = number / 100;
		rest = number % 100;
		convert_units(hundred, buffer, len);
		append_to_buffer(buffer, len, " hundred");
		if (rest > 0)
		{
			append_to_buffer(buffer, len, " and ");
			convert_tens(rest, buffer, len);
		}
	}
	else
		convert_tens(number, buffer, len);
}

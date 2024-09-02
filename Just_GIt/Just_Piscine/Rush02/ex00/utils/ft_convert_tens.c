/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_tens.c                                  :+:      :+:    :+:   */
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

void	convert_tens(int number, char *buffer, size_t *len)
{
	int			ten;
	int			unit;
	const char	*tens[] = {"", "", "twenty", "thirty",
		"forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

	if (number < 20)
		convert_units(number, buffer, len);
	else
	{
		ten = number / 10;
		unit = number % 10;
		append_to_buffer(buffer, len, tens[ten]);
		if (unit > 0)
		{
			append_to_buffer(buffer, len, "-");
			convert_units(unit, buffer, len);
		}
	}
}

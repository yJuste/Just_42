/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Converts str into long.                                                */
/*   • Prototype:   LONG ( char *, char **, int )                             */
/* ************************************************************************** */
#include "just_lib.h"

/*
long	ft_strtol(const char *nptr, char **endptr, int base)
{
	const char	*ptr;
	long			result;
	int			sign;
	int			digit;

	ptr = nptr;
	result = 0;
	sign = 1;
	while (*ptr == ' ' || (*ptr >= '\t' && *ptr <= '\r'))
		ptr++;
	if (*ptr == '-')
	{
		sign = -1;
		ptr++;
	}
	else if (*ptr == '+')
		ptr++;
	if (base < 2 || base > 36) {
		if (endptr)
			*endptr = (char *)nptr;
		return (0);
	}
	while (*ptr)
	{
		digit = 0;
		if (*ptr >= '0' && *ptr <= '9')
			digit = *ptr - '0';
		else if (*ptr >= 'a' && *ptr <= 'z')
			digit = *ptr - 'a' + 10;
		else if (*ptr >= 'A' && *ptr <= 'Z')
			digit = *ptr - 'A' + 10;
		else
			break;
		if (digit >= base)
			break;
		if (result > (LONG_MAX - digit) / base)
		{
			errno = ERANGE;
			if (endptr)
				*endptr = (char *)ptr;
			return (sign == 1) ? LONG_MAX : LONG_MIN;
		}
		result = result * base + digit;
		ptr++;
	}
	
	if (endptr)
		*endptr = (char *)ptr;
	return (result * sign);
}
*/

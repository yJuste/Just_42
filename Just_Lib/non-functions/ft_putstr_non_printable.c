/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Returns a str with a capital letter on the 1st letter of a wd.         */
/*   • Prototype:   VOID ( char * )                                           */
/*        -> write, size_t                                                    */
/* ************************************************************************** */
#include "../just_lib.h"

void	ft_putstr_non_printable(char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			ft_hex(str[i]);
		else
			ft_putchar(str[i]);
		i++;
	}
}

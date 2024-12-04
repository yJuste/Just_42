/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Awnis'                              #+#    #+#             */
/*   Updated:   by Awnis'                             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cube.h"

// -------------------------PROTOTYPE--------------------------
float		vabs(float n);
char		get_random_char(void);
// ------------------------------------------------------------

float	vabs(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	get_random_char(void)
{
	int		random_char;

	random_char= rand() % (126 - 32 + 1) + 32;
	return ((char)random_char);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Awnis'                              #+#    #+#             */
/*   Updated:   by Awnis'                             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cube.h"

// -------------------------PROTOTYPE--------------------------
void		rotatey(float point[3]);
void		rotatex(float point[3]);
void		rotatez(float point[3]);
// ------------------------------------------------------------

void	rotatey(float point[3])
{
	float		x;
	float		z;

	x = (point[0] * cos(degre)) - (point[2] * sin(degre));
	z = (point[0] * sin(degre)) + (point[2] * cos(degre));
	point[0] = x;
	point[2] = z;
	return ;
}

void	rotatex(float point[3])
{
	float		x;
	float		z;

	x = (point[0] * cos(degre)) - (point[1] * sin(degre));
	z = (point[0] * sin(degre)) + (point[1] * cos(degre));
	point[0] = x;
	point[1] = z;
	return ;
}

void	rotatez(float point[3])
{
	float		x;
	float		z;

	x = (point[1] * cos(degre * 2)) - (point[2] * sin(degre * 2));
	z = (point[1] * sin(degre * 2)) + (point[2] * cos(degre * 2));
	point[1] = x;
	point[2] = z;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Awnis'                              #+#    #+#             */
/*   Updated:   by Awnis'                             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Functions for resolving the mathematic part.                           */
/* ************************************************************************** */
#include "cube.h"

// -------------------------------PROTOTYPE-------------------------------
int			xy_to_str(float x, float y);
void		xyz_to_xy(t_params *params, float point[3], float res[2]);
void		rotatey(t_params *params, float point[3]);
void		rotatex(t_params *params, float point[3]);
void		rotatez(t_params *params, float point[3]);
// -----------------------------------------------------------------------

int	xy_to_str(float x, float y)
{
	int		resx;
	int		resy;

	resx = roundf(y) / 2;
	resy = roundf(x);
	return (resx * 102 + resy);
}

void	xyz_to_xy(t_params *params, float point[3], float res[2])
{
	float		vabs;

	vabs = params->camera[2] - point[2];
	if (vabs < 0)
		vabs = -vabs;
	res[0] = (point[1] * params->fov) / vabs;
	res[1] = (point[0] * params->fov) / vabs;
}

void	rotatey(t_params *params, float point[3])
{
	float		x;
	float		z;

	x = (point[0] * cos(params->degre)) - (point[2] * sin(params->degre));
	z = (point[0] * sin(params->degre)) + (point[2] * cos(params->degre));
	point[0] = x;
	point[2] = z;
}

void	rotatex(t_params *params, float point[3])
{
	float		x;
	float		z;

	x = (point[0] * cos(params->degre)) - (point[1] * sin(params->degre));
	z = (point[0] * sin(params->degre)) + (point[1] * cos(params->degre));
	point[0] = x;
	point[1] = z;
}

void	rotatez(t_params *params, float point[3])
{
	float		x;
	float		z;

	x = (point[1] * cos(params->degre * 2))
		- (point[2] * sin(params->degre * 2));
	z = (point[1] * sin(params->degre * 2))
		+ (point[2] * cos(params->degre * 2));
	point[1] = x;
	point[2] = z;
}

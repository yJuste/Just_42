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
void		xyz_to_xy(t_params *params, float point[3], float res[2]);
int			xy_to_str(float x, float y);
char		dist_to_ascii(t_params *params, float distance);
float		dist_3d(t_params *params, float p1[3]);
float		vabs(float n);
// -----------------------------------------------------------------------

void	xyz_to_xy(t_params *params, float point[3], float res[2])
{
	res[0] = (point[1] * params->fov)
		/ vabs(params->camera[2] - point[2]);
	res[1] = (point[0] * params->fov)
		/ vabs(params->camera[2] - point[2]);
	return ;
}

int	xy_to_str(float x, float y)
{
	int		resx;
	int		resy;

	resx = roundf(y) / 2;
	resy = roundf(x);
	return (resx * 102 + resy);
}

char	dist_to_ascii(t_params *params, float distance)
{
	int		res;

	res = roundf(distance / 2);
	if (res >= 52)
		res = 52;
	return (params->ascii[res - 10]);
}

float	dist_3d(t_params *params, float p1[3])
{
	int		res;

	res = vabs(p1[2] - params->camera[2]);
	return (res);
}

float	vabs(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

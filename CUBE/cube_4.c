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

// -------------------------PROTOTYPE-------------------------
void		rotatey(t_params *params, float point[3]);
void		rotatex(t_params *params, float point[3]);
void		rotatez(t_params *params, float point[3]);
void		drawline(float p1[2], float p2[2], char *str);
char		get_random_char(void);
// -----------------------------------------------------------

void	rotatey(t_params *params, float point[3])
{
	float		x;
	float		z;

	x = (point[0] * cos(params->degre)) - (point[2] * sin(params->degre));
	z = (point[0] * sin(params->degre)) + (point[2] * cos(params->degre));
	point[0] = x;
	point[2] = z;
	return ;
}

void	rotatex(t_params *params, float point[3])
{
	float		x;
	float		z;

	x = (point[0] * cos(params->degre)) - (point[1] * sin(params->degre));
	z = (point[0] * sin(params->degre)) + (point[1] * cos(params->degre));
	point[0] = x;
	point[1] = z;
	return ;
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
	return ;
}

void	drawline(float p1[2], float p2[2], char *str)
{
	int			steps;
	int			i;
	float		t;
	float		x;
	float		y;

	steps = (int)(sqrt((p2[0] - p1[0]) * (p2[0] - p1[0])
				+ (p2[1] - p1[1]) * (p2[1] - p1[1])) * 10);
	i = 0;
	while (i <= steps)
	{
		t = i / (float)steps;
		x = p1[0] + t * (p2[0] - p1[0]);
		y = p1[1] + t * (p2[1] - p1[1]);
		str[xy_to_str(x, y)] = get_random_char();
		i++;
	}
	return ;
}

char	get_random_char(void)
{
	int		random_char;

	random_char = rand() % (126 - 32 + 1) + 32;
	return ((char)random_char);
}

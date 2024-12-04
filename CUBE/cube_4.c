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
void		drawline(float p1[2], float p2[2], char *str);
int			get_ascii(int indexchar, char *str);
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

void	drawline(float p1[2], float p2[2], char *str)
{
	int			steps;
	int			i;
	float		dx;
	float		dy;
	float		distance;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	distance = sqrt(dx * dx + dy * dy);
	steps = (int)(distance * 10);
	i = 0;
	while (i <= steps)
	{
		float t = i / (float)steps;
		float x = p1[0] + t * dx;
		float y = p1[1] + t * dy;
		str[xy_to_str(x, y)] = get_random_char();
		i++;
	}
}

int	get_ascii(int indexchar, char *str)
{
	int		i;
	char	c;

	i = 0;
	c = str[indexchar];
	while (ascii[i] != c)
		i++;
	return (i);
}

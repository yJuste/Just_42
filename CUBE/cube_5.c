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
void		drawline(float p1[2], float p2[2], char *str);
char		get_random_char(void);
int			get_ascii(int indexchar, char *str);
// ------------------------------------------------------------

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

char	get_random_char(void)
{
	int		random_char;

	random_char= rand() % (126 - 32 + 1) + 32;
	return ((char)random_char);
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

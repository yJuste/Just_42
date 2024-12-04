/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Awnis'                              #+#    #+#             */
/*   Updated:   by Awnis'                             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cube.h"

// ----------------------------------PROTOTYPE----------------------------------
void		strchange(t_params *params, t_pxx *pxx, char *str, char *str2);
void		strchange_2(t_params *params, t_pxx *pxx, char *str);
void		strchange_3(t_params *params, t_pxx *pxx, char *str);
void		strchange_4(t_params *params, t_pxx *pxx, char *str);
void		strchange_next(t_params *params, t_pxx *pxx);
// -----------------------------------------------------------------------------

void	strchange(t_params *params, t_pxx *pxx, char *str, char *str2)
{
	int		i;

	i = -1;
	printf("\033[H\033[J");
	memcpy(str, str2, strlen(str2) + 1);
	xyz_to_xy(params, params->tableau[0], pxx->p01);
	xyz_to_xy(params, params->tableau[1], pxx->p02);
	xyz_to_xy(params, params->tableau[2], pxx->p03);
	xyz_to_xy(params, params->tableau[3], pxx->p04);
	xyz_to_xy(params, params->tableau[4], pxx->p11);
	xyz_to_xy(params, params->tableau[5], pxx->p12);
	xyz_to_xy(params, params->tableau[6], pxx->p13);
	xyz_to_xy(params, params->tableau[7], pxx->p14);
	while (++i <= 1)
	{
		pxx->p01[0] += params->decalage;
		pxx->p02[0] += params->decalage;
		pxx->p03[0] += params->decalage;
		pxx->p04[0] += params->decalage;
		pxx->p11[0] += params->decalage;
		pxx->p12[0] += params->decalage;
		pxx->p13[0] += params->decalage;
		pxx->p14[0] += params->decalage;
	}
	strchange_2(params, pxx, str);
}

void	strchange_2(t_params *params, t_pxx *pxx, char *str)
{
	int		i;

	i = -1;
	while (++i <= 1)
	{
		pxx->p01[0] *= params->size;
		pxx->p02[0] *= params->size;
		pxx->p03[0] *= params->size;
		pxx->p04[0] *= params->size;
		pxx->p11[0] *= params->size;
		pxx->p12[0] *= params->size;
		pxx->p13[0] *= params->size;
		pxx->p14[0] *= params->size;
	}
	strchange_3(params, pxx, str);
}

void	strchange_3(t_params *params, t_pxx *pxx, char *str)
{
	str[xy_to_str(pxx->p01[0], pxx->p01[1])]
		= dist_to_ascii(params, dist_3d(params, params->tableau[0]));
	str[xy_to_str(pxx->p02[0], pxx->p02[1])]
		= dist_to_ascii(params, dist_3d(params, params->tableau[1]));
	str[xy_to_str(pxx->p03[0], pxx->p03[1])]
		= dist_to_ascii(params, dist_3d(params, params->tableau[2]));
	str[xy_to_str(pxx->p04[0], pxx->p04[1])]
		= dist_to_ascii(params, dist_3d(params, params->tableau[3]));
	str[xy_to_str(pxx->p11[0], pxx->p11[1])]
		= dist_to_ascii(params, dist_3d(params, params->tableau[4]));
	str[xy_to_str(pxx->p12[0], pxx->p12[1])]
		= dist_to_ascii(params, dist_3d(params, params->tableau[5]));
	str[xy_to_str(pxx->p13[0], pxx->p13[1])]
		= dist_to_ascii(params, dist_3d(params, params->tableau[6]));
	str[xy_to_str(pxx->p14[0], pxx->p14[1])]
		= dist_to_ascii(params, dist_3d(params, params->tableau[7]));
	rotatey(params->tableau[0]);
	rotatey(params->tableau[1]);
	rotatey(params->tableau[2]);
	rotatey(params->tableau[3]);
	rotatey(params->tableau[4]);
	rotatey(params->tableau[5]);
	rotatey(params->tableau[6]);
	rotatey(params->tableau[7]);
	strchange_4(params, pxx, str);
}

void	strchange_4(t_params *params, t_pxx *pxx, char *str)
{
	rotatex(params->tableau[0]);
	rotatex(params->tableau[1]);
	rotatex(params->tableau[2]);
	rotatex(params->tableau[3]);
	rotatex(params->tableau[4]);
	rotatex(params->tableau[5]);
	rotatex(params->tableau[6]);
	rotatex(params->tableau[7]);
	drawline(pxx->p01, pxx->p02, str);
	drawline(pxx->p03, pxx->p04, str);
	drawline(pxx->p01, pxx->p03, str);
	drawline(pxx->p02, pxx->p04, str);
	drawline(pxx->p11, pxx->p12, str);
	drawline(pxx->p13, pxx->p14, str);
	drawline(pxx->p11, pxx->p13, str);
	drawline(pxx->p12, pxx->p14, str);
	drawline(pxx->p01, pxx->p11, str);
	drawline(pxx->p02, pxx->p12, str);
	drawline(pxx->p03, pxx->p13, str);
	drawline(pxx->p04, pxx->p14, str);
	printf("%s", str);
	strchange_next(params, pxx);
}

void	strchange_next(t_params *params, t_pxx *pxx)
{
	int		console_width;
	int		i;
	int		j;
	float	*projection;

	i = 0;
	console_width = 80;
	while (i < 8)
	{
		if (i < 4)
			projection = pxx->p01;
		else
			projection = pxx->p11;
		printf("p%02d: projection x = %.2f, projection y = %.2f", i + 1,
			projection[0], projection[1]);
		j = -1;
		while (++j < console_width - 40)
			printf(" ");
		printf("p%02d: x = %.2f, y = %.2f, z = %.2f\n", i + 1,
			params->tableau[i][0],
			params->tableau[i][1],
			params->tableau[i][2]);
		i++;
	}
	usleep(50000);
}

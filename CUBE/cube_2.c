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
/*   • Determines specs and informations.                                     */
/* ************************************************************************** */
#include "cube.h"

// ----------------------------PROTOTYPE-----------------------------
void		strchange(t_params *params, t_pxx *pxx, char *str);
void		strchange_2(t_params *params, t_pxx *pxx, char *str);
void		strchange_3(t_params *params, t_pxx *pxx, char *str);
void		strchange_4(t_params *params, t_pxx *pxx, char *str);
void		strchange_next(t_params *params, t_pxx *pxx);
// ------------------------------------------------------------------

void	strchange(t_params *params, t_pxx *pxx, char *str)
{
	int		i;

	i = -1;
	printf("\033[H\033[J");
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
		pxx->p01[i] += params->decalage;
		pxx->p02[i] += params->decalage;
		pxx->p03[i] += params->decalage;
		pxx->p04[i] += params->decalage;
		pxx->p11[i] += params->decalage;
		pxx->p12[i] += params->decalage;
		pxx->p13[i] += params->decalage;
		pxx->p14[i] += params->decalage;
	}
	strchange_2(params, pxx, str);
}

void	strchange_2(t_params *params, t_pxx *pxx, char *str)
{
	int		i;

	i = -1;
	while (++i <= 1)
	{
		pxx->p01[i] *= params->size;
		pxx->p02[i] *= params->size;
		pxx->p03[i] *= params->size;
		pxx->p04[i] *= params->size;
		pxx->p11[i] *= params->size;
		pxx->p12[i] *= params->size;
		pxx->p13[i] *= params->size;
		pxx->p14[i] *= params->size;
	}
	strchange_3(params, pxx, str);
}

void	strchange_3(t_params *params, t_pxx *pxx, char *str)
{
	rotatey(params, params->tableau[0]);
	rotatey(params, params->tableau[1]);
	rotatey(params, params->tableau[2]);
	rotatey(params, params->tableau[3]);
	rotatey(params, params->tableau[4]);
	rotatey(params, params->tableau[5]);
	rotatey(params, params->tableau[6]);
	rotatey(params, params->tableau[7]);
	strchange_4(params, pxx, str);
}

void	strchange_4(t_params *params, t_pxx *pxx, char *str)
{
	rotatex(params, params->tableau[0]);
	rotatex(params, params->tableau[1]);
	rotatex(params, params->tableau[2]);
	rotatex(params, params->tableau[3]);
	rotatex(params, params->tableau[4]);
	rotatex(params, params->tableau[5]);
	rotatex(params, params->tableau[6]);
	rotatex(params, params->tableau[7]);
	drawline(params, pxx->p01, pxx->p02, str);
	drawline(params, pxx->p03, pxx->p04, str);
	drawline(params, pxx->p01, pxx->p03, str);
	drawline(params, pxx->p02, pxx->p04, str);
	drawline(params, pxx->p11, pxx->p12, str);
	drawline(params, pxx->p13, pxx->p14, str);
	drawline(params, pxx->p11, pxx->p13, str);
	drawline(params, pxx->p12, pxx->p14, str);
	drawline(params, pxx->p01, pxx->p11, str);
	drawline(params, pxx->p02, pxx->p12, str);
	drawline(params, pxx->p03, pxx->p13, str);
	drawline(params, pxx->p04, pxx->p14, str);
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

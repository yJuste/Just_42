/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Awnis'                              #+#    #+#             */
/*   Updated:   by Awnis'                             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Shows a rotating cube in 3D.                                           */
/*   • ./a.out [ taille ] [ vitesse ]                                         */
/*      -> taille        [ -50 <=> 50 ]                                       */
/*      -> vitesse       [ -1 <=> 1 ]                                         */
/*      -> Ajouter un moins devant la taille ou la vitesse, peut changer      */
/*           la rotation du cube.                                             */
/* ************************************************************************** */
#ifndef CUBE_H
# define CUBE_H

// Standard Libraries

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <unistd.h>
# include <time.h>

// Structures

typedef struct s_params
{
	float		tableau[8][3];
	float		camera[3];
	float		fov;
	float		degre;
	float		size;
	int			decalage;
	char		*ascii;
}	t_params;

typedef struct s_pxx
{
	float		p01[2];
	float		p02[2];
	float		p03[2];
	float		p04[2];
	float		p11[2];
	float		p12[2];
	float		p13[2];
	float		p14[2];
}	t_pxx;

//	---------- THE CODE ----------

// cube.c

int			main(int argc, char **argv);
void		ft_change_parameters(t_params *params, int argc, char **argv);
char		*creer_chaine(int lignes, int espaces_par_ligne);
void		ft_init_params(t_params *params);
void		ft_init_tableau(t_params *params);

// cube_2.c

void		strchange(t_params *params, t_pxx *pxx, char *str);
void		strchange_2(t_params *params, t_pxx *pxx, char *str);
void		strchange_3(t_params *params, t_pxx *pxx, char *str);
void		strchange_4(t_params *params, t_pxx *pxx, char *str);
void		strchange_next(t_params *params, t_pxx *pxx);

// cube_3.c

void		xyz_to_xy(t_params *params, float point[3], float res[2]);
int			xy_to_str(float x, float y);
char		dist_to_ascii(t_params *params, float distance);
float		dist_3d(t_params *params, float p1[3]);
float		vabs(float n);

// cube_4.c

void		rotatey(t_params *params, float point[3]);
void		rotatex(t_params *params, float point[3]);
void		rotatez(t_params *params, float point[3]);
void		drawline(float p1[2], float p2[2], char *str);
char		get_random_char(void);

#endif

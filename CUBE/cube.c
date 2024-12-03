/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Awnis'                              #+#    #+#             */
/*   Updated:   by Awnis'                             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

float tableau[8][3] = {
	{-30, 30, 30},
	{30, 30, 30},
	{-30, -30, 30},
	{30, -30, 30},
	{-30, 30, -30},
	{30, 30, -30},
	{-30, -30, -30},
	{30, -30, -30}
};

float camera[3] = {0, 0, 70};
float FOV = 50;
float degre = 0.05;
float size = 0.8;
int decalage = 70;

char *ascii = "@&NM0KAUh6PkqwSE2]ayjx[IifFJ)vTz/*cr!+><;=^,:'-.` "; // 52 caracteres

float	vabs(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	dist_to_ascii(float distance)
{
	int		res;

	res = roundf(distance / 2);
	if (res >= 52)
		res = 52;
	return (ascii[res - 10]);
}

float	dist_3d(float p1[3])
{
	int		res;

	res = vabs(p1[2] - camera[2]);
	return (res);
}

char	get_random_char()
{
	int		random_char;

	random_char= rand() % (126 - 32 + 1) + 32;
	return ((char)random_char);
}

char	*creer_chaine(int lignes, int espaces_par_ligne)
{
	int		taille_totale;
	int		i;
	char	*chaine;

	taille_totale = lignes * (espaces_par_ligne + 1) + 1;
	chaine = malloc(sizeof(char) * taille_totale);
	if (chaine == NULL)
	{
		printf("Erreur d'allocation de mémoire.\n");
		return (NULL);
	}
	i = 0;
	while (i < lignes)
	{
		memset(chaine + i * (espaces_par_ligne + 1), ' ', espaces_par_ligne);
		chaine[i * (espaces_par_ligne + 1) + espaces_par_ligne] = '\n';
		i++;
	}
	chaine[taille_totale - 1] = '\0';
	return (chaine);
}

void	xyz_to_xy(float point[3], float res[2])
{
	res[0] = (point[1] * FOV) / vabs(camera[2] - point[2]);
	res[1] = (point[0] * FOV) / vabs(camera[2] - point[2]);
}

int	xy_to_str(float x, float y)
{
	int		resx;
	int		resy;

	resx = roundf(y) / 2;
	resy = roundf(x);
	return (resx * 102 + resy);
}

void	rotatey(float point[3])
{
	float		x;
	float		z;

	x = (point[0] * cos(degre)) - (point[2] * sin(degre));
	z = (point[0] * sin(degre)) + (point[2] * cos(degre));
	point[0] = x;
	point[2] = z;
}

void	rotatex(float point[3])
{
	float		x;
	float		z;

	x = (point[0] * cos(degre)) - (point[1] * sin(degre));
	z = (point[0] * sin(degre)) + (point[1] * cos(degre));
	point[0] = x;
	point[1] = z;
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

void	strchange(char *str, char *str2)
{
	printf("\033[H\033[J");
	memcpy(str, str2, strlen(str2) + 1);

	float p01[2];
	float p02[2];
	float p03[2];
	float p04[2];
	float p11[2];
	float p12[2];
	float p13[2];
	float p14[2];

	xyz_to_xy(tableau[0], p01);
	xyz_to_xy(tableau[1], p02);
	xyz_to_xy(tableau[2], p03);
	xyz_to_xy(tableau[3], p04);
	xyz_to_xy(tableau[4], p11);
	xyz_to_xy(tableau[5], p12);
	xyz_to_xy(tableau[6], p13);
	xyz_to_xy(tableau[7], p14);

	p01[0] += decalage; p01[1] += decalage;
	p02[0] += decalage; p02[1] += decalage;
	p03[0] += decalage; p03[1] += decalage;
	p04[0] += decalage; p04[1] += decalage;
	p11[0] += decalage; p11[1] += decalage;
	p12[0] += decalage; p12[1] += decalage;
	p13[0] += decalage; p13[1] += decalage;
	p14[0] += decalage; p14[1] += decalage;

	p01[0] *= size; p01[1] *= size;
	p02[0] *= size; p02[1] *= size;
	p03[0] *= size; p03[1] *= size;
	p04[0] *= size; p04[1] *= size;
	p11[0] *= size; p11[1] *= size;
	p12[0] *= size; p12[1] *= size;
	p13[0] *= size; p13[1] *= size;
	p14[0] *= size; p14[1] *= size;

	str[xy_to_str(p01[0], p01[1])] = dist_to_ascii(dist_3d(tableau[0]));
	str[xy_to_str(p02[0], p02[1])] = dist_to_ascii(dist_3d(tableau[1]));
	str[xy_to_str(p03[0], p03[1])] = dist_to_ascii(dist_3d(tableau[2]));
	str[xy_to_str(p04[0], p04[1])] = dist_to_ascii(dist_3d(tableau[3]));
	str[xy_to_str(p11[0], p11[1])] = dist_to_ascii(dist_3d(tableau[4]));
	str[xy_to_str(p12[0], p12[1])] = dist_to_ascii(dist_3d(tableau[5]));
	str[xy_to_str(p13[0], p13[1])] = dist_to_ascii(dist_3d(tableau[6]));
	str[xy_to_str(p14[0], p14[1])] = dist_to_ascii(dist_3d(tableau[7]));
	
	rotatey(tableau[0]);
	rotatey(tableau[1]);
	rotatey(tableau[2]);
	rotatey(tableau[3]);
	rotatey(tableau[4]);
	rotatey(tableau[5]);
	rotatey(tableau[6]);
	rotatey(tableau[7]);

	rotatex(tableau[0]);
	rotatex(tableau[1]);
	rotatex(tableau[2]);
	rotatex(tableau[3]);
	rotatex(tableau[4]);
	rotatex(tableau[5]);
	rotatex(tableau[6]);
	rotatex(tableau[7]); 

	drawline(p01, p02, str);
	drawline(p03, p04, str);
	drawline(p01, p03, str);
	drawline(p02, p04, str);

	drawline(p11, p12, str);
	drawline(p13, p14, str);
	drawline(p11, p13, str);
	drawline(p12, p14, str);

	drawline(p01, p11, str);
	drawline(p02, p12, str);
	drawline(p03, p13, str);
	drawline(p04, p14, str);


	printf("%s", str);
	int		console_width;
	int		i;
	int		j;

	i = 0;
	console_width = 80;
	while (i < 8)
	{
		float *projection = (i < 4) ? p01 : p11;  // Choisir p01 ou p11 selon l'indice
		printf("p%02d: projection x = %.2f, projection y = %.2f", i + 1, projection[0], projection[1]);
		j = 0;
		while (j < console_width - 40)
		{
			printf(" ");
			j++;
		}
		printf("p%02d: x = %.2f, y = %.2f, z = %.2f\n", i + 1, tableau[i][0], tableau[i][1], tableau[i][2]);
		i++;
	}
	usleep(50000);
}

int	main(void)
{
	int		lignes = 52;
	int		espaces_par_ligne = 101;
	char	*chaine;
	char	*chaine2;

	chaine = creer_chaine(lignes, espaces_par_ligne);
	chaine2 = creer_chaine(lignes, espaces_par_ligne);
	if (!chaine2 || !chaine)
		return (1);
	while (1)
		strchange(chaine, chaine2);
	free(chaine);
	return (0);
}

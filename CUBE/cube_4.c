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
/*   • Functions for rotating, drawings and symbols.                          */
/* ************************************************************************** */
#include "cube.h"

// ----------------------------------PROTOTYPE----------------------------------
void		drawline(t_params *params, float p1[2], float p2[2], char *str);
char		get_random_char(t_params *params);
char		*creer_chaine(int lignes, int espaces_par_ligne);
void		ft_init_params(t_params *params);
void		ft_init_tableau(t_params *params);
// -----------------------------------------------------------------------------

void	drawline(t_params *params, float p1[2], float p2[2], char *str)
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
		str[xy_to_str(x, y)] = get_random_char(params);
		i++;
	}
	return ;
}

char	get_random_char(t_params *params)
{
	int					random_char;
	static unsigned int	i = 0;

	if (params->ascii == NULL || strcmp(params->ascii, "") == 0)
		random_char = rand() % (126 - 32 + 1) + 32;
	else
	{
		random_char = params->ascii[i];
		i++;
		if (strlen(params->ascii) == i)
			i = 0;
	}
	return ((char)random_char);
}

char	*creer_chaine(int lignes, int espaces_par_ligne)
{
	int		taille_totale;
	int		i;
	char	*chaine;

	taille_totale = lignes * (espaces_par_ligne + 1) + 1;
	chaine = malloc(sizeof(char) * taille_totale);
	if (!chaine)
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

void	ft_init_params(t_params *params)
{
	ft_init_tableau(params);
	params->camera[0] = 0;
	params->camera[1] = 0;
	params->camera[2] = 70;
	params->decalage = 70;
	params->fov = -50;
	params->degre = -0.03;
	params->size = 0.8;
	params->ascii = "";
}

void	ft_init_tableau(t_params *params)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (i % 2 == 0)
			params->tableau[i][0] = -30;
		else
			params->tableau[i][0] = 30;
		if ((i & 2) != 0)
			params->tableau[i][1] = -30;
		else
			params->tableau[i][1] = 30;
		if ((i & 4) != 0)
			params->tableau[i][2] = -30;
		else
			params->tableau[i][2] = 30;
		i++;
	}
	return ;
}

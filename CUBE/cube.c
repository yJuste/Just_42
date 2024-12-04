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
/*   • Shows a rotating cube in 3D.                                           */
/*   • ./a.out [ taille ] [ vitesse ]                                         */
/*      -> taille        [ -50 <=> 50 ]                                       */
/*      -> vitesse       [ -1 <=> 1 ]                                         */
/*      -> Ajouter un moins devant la taille ou la vitesse, peut changer      */
/*           la rotation du cube.                                             */
/* ************************************************************************** */
#include "cube.h"

// ----------------------------------PROTOTYPE--------------------------------
int			main(int argc, char **argv);
void		ft_change_parameters(t_params *params, int argc, char **argv);
char		*creer_chaine(int lignes, int espaces_par_ligne);
void		ft_init_params(t_params *params);
void		ft_init_tableau(t_params *params);
// ---------------------------------------------------------------------------

int	main(int argc, char **argv)
{
	t_params	params;
	t_pxx		pxx;
	char		*chaine;

	ft_init_params(&params);
	ft_change_parameters(&params, argc, argv);
	while (1)
	{
		chaine = creer_chaine(52, 101);
		if (!chaine)
			return (1);
		strchange(&params, &pxx, chaine);
		free(chaine);
	}
	return (0);
}

void	ft_change_parameters(t_params *params, int argc, char **argv)
{
	float		taille;
	float		vitesse;

	if (argc == 2 || argc == 3)
	{
		taille = strtof(argv[1], NULL);
		if (taille >= -50 && taille <= 50)
			params->fov = taille;
		if (argc == 3)
		{
			vitesse = strtof(argv[2], NULL);
			if (vitesse >= -1 && vitesse <= 1)
				params->degre = vitesse;
		}
		return ;
	}
	if (argc > 3)
	{
		printf("Error, please do :\n	--- `make help` ---\n");
		exit(2);
	}
	return ;
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
	params->fov = -50;
	params->degre = -0.04;
	params->size = 0.8;
	params->decalage = 70;
	params->ascii = "@&NM0KAUh6PkqwSE2]ayjx[IifFJ)vTz/*cr!+><;=^,:'-.` ";
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

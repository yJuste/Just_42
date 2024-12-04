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
#include "cube.h"

// --------------------------PROTOTYPE---------------------------
int			main(void);
char		*creer_chaine(int lignes, int espaces_par_ligne);
void		ft_init_params(t_params *params);
void		ft_init_tableau(t_params *params);
// --------------------------------------------------------------

int	main(void)
{
	t_params	params;
	t_pxx		pxx;
	char		*chaine;

	ft_init_params(&params);
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
	params->fov = 50;
	params->degre = 0.05;
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

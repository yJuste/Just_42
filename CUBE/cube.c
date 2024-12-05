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
/*   • ./a.out [ characters ] [ taille ] [ vitesse ]                          */
/*      -> characters    [   asciis   ]                                       */
/*      -> taille        [ -50 <=> 50 ]                                       */
/*      -> vitesse       [  -1 <=> 1  ]                                       */
/*      -> Ajouter un moins devant la taille ou la vitesse, change la         */
/*            rotation du cube.                                               */
/* ************************************************************************** */
#include "cube.h"

// ------------------------------PROTOTYPE-----------------------------
int			main(int argc, char **argv);
void		ft_parameters(t_params *params, int argc, char **argv);
// --------------------------------------------------------------------

int	main(int argc, char **argv)
{
	t_params	params;
	t_pxx		pxx;
	char		*chaine;

	ft_init_params(&params);
	ft_parameters(&params, argc, argv);
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

void	ft_parameters(t_params *params, int argc, char **argv)
{
	float		taille;
	float		vitesse;

	if (argc == 2 || argc == 3 || argc == 4)
	{
		params->ascii = argv[1];
		if (argc == 3)
		{
			vitesse = strtof(argv[2], NULL);
			if (vitesse >= -1 && vitesse <= 1)
				params->degre = vitesse;
			if (argc == 4)
			{
				taille = strtof(argv[3], NULL);
				if (taille >= -50 && taille <= 50)
					params->fov = taille;
			}
		}
	}
	if (argc > 3)
	{
		printf("Error, please do :\n	--- `make help` ---\n");
		exit(2);
	}
}

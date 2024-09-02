/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int mini_verif_colonne(char *col_haute, char *col_basse)
{
	int	somme;
	int	i;

	somme = 0;
	i = 0;
	while (col_haute[i])
	{
		somme += char_to_int(col_haute[i]) + char_to_int(col_basse[i]);
		if ((char_to_int(col_haute[i]) + char_to_int(col_basse[i])) > 5)
		{
			return (0);
		}
		i++;
	}
	return (somme);
}

int	mini_verif_ligne(char *line_gauche, char *line_droite)
{
	int	somme;
	int	j;

	somme = 0;
	j = 0;
	while (line_gauche[j])
	{
		somme += char_to_int(line_gauche[j]) + char_to_int(line_droite[j]);
		if ((char_to_int(line_gauche[j]) + char_to_int(line_droite[j])) > 5)
		{
			return (0);
		}
		j++;
	}
	return (somme);
}

int	verif(char *col_haute, char *col_basse, char *line_gauche, char *line_droite)
{
	int	somme;
	
	somme = mini_verif_ligne(line_gauche, line_droite) + mini_verif_colonne(col_haute, col_basse);
	if (somme < 32 || somme > 35)
	{
		write(1, "mauvais input\n", 15);
		return (0);
	}
	write(1, "bon input\n", 11);
	return (1);
}
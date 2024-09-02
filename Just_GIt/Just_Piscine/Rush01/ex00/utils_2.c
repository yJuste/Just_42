/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*colonne(char a, char b, char c, char d)
{
	char	*tableau;
	tableau = (char*)malloc(5 * sizeof(char));

	tableau[0] = a;
	tableau[1] = b;
	tableau[2] = c;
	tableau[3] = d;

	return (tableau);
}

int	max_int(char **argv, char cible)
{
	int	j;
	int	i;
	int	occ;

	j = 4;
	i = 0;
	occ = 0;
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (argv[j][i] == cible)
				occ++;
			i++;
		}
		j++;
	}
	return (occ);
}
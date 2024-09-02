/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    paterns_4_1(char **argv, int i);
void    paterns_1_4(char **argv, int i);
void    patern_3_1_3_2(char **argv, int i);
void	paterns_2_1(char **argv, int i);

/*int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char *enleve_espace(char *str)
{
    int i;
	int j;

    // Allouer de la mémoire pour la chaîne résultante
    char *dest = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
    if (dest == NULL)
        return NULL;  // Vérifier si l'allocation a échoué

    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            dest[j] = str[i];
            j++;
        }
        i++;
    }
    dest[j] = '\0';  // Terminer la chaîne par un caractère nul
    return dest;
}

int char_to_int(char c)
{
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else {
        return -1;
    }
}*/

/*int mini_verif_colonne(char *col_haute, char *col_basse)
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
}*/

char	**map(char *col_haute, char *col_basse, char *line_gauche, char *line_droite)
{
	int i;
	int	j;

	i = 4;
	j = 0;
	char	**tableau = (char **)malloc(8 * sizeof(char *));
	tableau[0] = col_haute;
	tableau[1] = col_basse;
	tableau[2] = line_gauche;
	tableau[3] = line_droite;
	while (i < 8)
	{
		tableau[i] = (char *)malloc(8 * sizeof(char));
		while (j < 4)
		{
			tableau[i][j] = '0';
			j++;
		}
		j = 0;
		i++;
	}
	return (tableau);
}

char **jeu(char **argv)
{
    int i;
    int j;
    char nombre;

	i = 0;
    nombre = '1';

    // Boucle principale pour parcourir les caractères de argv[0]
    while (argv[0][i])
    {
		j = 4; // Réinitialiser j à chaque itération
		paterns_4_1(argv, i);
		paterns_1_4(argv, i);
		patern_3_1_3_2(argv, i);
		paterns_2_1(argv, i);
		i++;
	}
	i = 0;
	while (argv[2][i])
	{
		j = 0;
		if (argv[2][i] == '1')
        {
            argv[i+4][0] = '4';
        }
		
        if (argv[2][i] == '4' && argv[3][i] == '1')
        {
			nombre = '1';
            // Remplir les éléments de argv[4] à argv[7]
            while (j < 4)
            {
                argv[i+4][j] = nombre;
                j++;
                nombre++;
            }
			j = 0; // Réinitialiser j à chaque itération
        }
		if (argv[2][i] == '1' && argv[3][i] == '4')
        {
            nombre = '4';
			// Remplir les éléments de argv[4] à argv[7]
            while (j < 4)
            {
                argv[i+4][j] = nombre;
                j++;
                nombre--;
            }
			j = 0; // Réinitialiser j à chaque itération
		}	

        if (argv[2][i] == '3' && argv[3][i] == '2')
        {
            argv[i+4][2] = '4';
        }
		if (argv[2][i] == '2' && argv[3][i] == '3')
        {
            argv[i+4][1] = '4';
        }

		if (argv[2][i] == '3' && argv[3][i] == '1')
		{
			argv[i+4][3] = '4';
		}
		if (argv[2][i] == '1' && argv[3][i] == '3')
		{
			argv[i+4][0] = '4';
		}

		if (argv[2][i] == '2' && argv[3][i] == '1')
		{
			argv[i+4][3] = '4';
			argv[i+4][0] = '3';
		}
		if (argv[2][i] == '1' && argv[3][i] == '2')
		{
			argv[i+4][0] = '4';
			argv[i+4][3] = '3';
		}
		i++;
	}
	j = 4;
	while (argv[j])
	{
		write(1, argv[j], 4);
		write(1, "\n", 1);
		j++;
	}
    return (argv);
}

/*int	max_int(char **argv, char cible)
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
}*/

char	**jeu_v2(char **argv)
{
	int	occ_1;
    int	occ_2;
    int	occ_3;
    int	occ_4;
	int	i;
	int	k;
	int	max;
	char	max_str;

	occ_1 = max_int(argv, '1');
    occ_2 = max_int(argv, '2');
    occ_3 = max_int(argv, '3');
    occ_4 = max_int(argv, '4');

    int *tableau;
	i = 0;
	max = 0;
    tableau = (int *)malloc(5 * sizeof(int));
    tableau[0] = occ_1;
    tableau[1] = occ_2;
    tableau[2] = occ_3;
    tableau[3] = occ_4;
    while (tableau[i])
    {
        max = tableau[i];
        if (tableau[i] > max)
			max = tableau[i];
		if (max == 4)
		{
			tableau[i] = 0;
			i = -1;
		}
        i++;
    }
	i = 4;
	k = 0;
	while (argv[i])
	{
		if (present_dans(argv[i], max_str) == 1 || present_dans(argv[i], '0') == 0)
		{
			i++;
			continue;
		}
		while (argv[i][k])
		{
			if (argv[i][k] == '0')
			{
				if (present_dans(colonne(argv[4][k], argv[5][k], argv[6][k], argv[7][k]), max_str) == 1)
				{
					k++;
					continue;
				}
				else
				{
					/*if ()*/
					{
						/* code */
					}
				}
			}
			k++;
		}
		i++;
	}
	
}

/*int	present_dans(char *tableau, char c)
{
	int	i;

	i = 0;
	while (tableau[i])
	{
		if (tableau[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
	
}*/

/*char	*colonne(char a, char b, char c, char d)
{
	char	*tableau;
	tableau = (char*)malloc(5 * sizeof(char));

	tableau[0] = a;
	tableau[1] = b;
	tableau[2] = c;
	tableau[3] = d;

	return (tableau);
}*/

int	main(int ac, char **argv)
{
	if (ac != 2)
	{
		write(1, "fdp", 3);
		return (0);
	}
	char	*vrai_argv;
	vrai_argv = enleve_espace(argv[1]);

	char	*ht_col = (char *)malloc(((ft_strlen(vrai_argv) / 4) + 1) * sizeof(char));
	char	*bas_col = (char *)malloc(((ft_strlen(vrai_argv) / 4) + 1) * sizeof(char));
	char	*cote_gauche = (char *)malloc(((ft_strlen(vrai_argv) / 4) + 1) * sizeof(char));
	char	*cote_droit = (char *)malloc(((ft_strlen(vrai_argv) / 4) + 1) * sizeof(char));

	ft_strncpy(ht_col, vrai_argv, 4);
	ft_strncpy(bas_col, &vrai_argv[4], 4);
	ft_strncpy(cote_gauche, &vrai_argv[8], 4);
	ft_strncpy(cote_droit, &vrai_argv[12], 4);

	//char	**tableau;
	verif(ht_col, bas_col, cote_gauche, cote_droit);
	(jeu(map(ht_col, bas_col, cote_gauche, cote_droit)));
	return (0);
}

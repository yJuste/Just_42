/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paterns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void    paterns_4_1(char **argv, int i)
{
    int j;
    char    nombre;
    
    j = 4;
    if (argv[0][i] == '4' && argv[1][i] == '1')
    {
		nombre = '1';
        // Remplir les éléments de argv[4] à argv[7]
        while (j < 8)
        {
            argv[j][i] = nombre;
            j++;
            nombre++;
        }
    }
}

void    paterns_1_4(char **argv, int i)
{
    char    nombre;
	int	j;
    
    j = 4;
    if (argv[0][i] == '1' && argv[1][i] == '4')
    {
		nombre = '4';
        // Remplir les éléments de argv[4] à argv[7]
        while (j < 8)
        {
            argv[j][i] = nombre;
            j++;
            nombre--;
        }
    }
}

void    patern_3_1_3_2(char **argv, int i)
{
    if (argv[0][i] == '3' && argv[1][i] == '2')
    {
        argv[6][i] = '4';
    }
	else if (argv[0][i] == '2' && argv[1][i] == '3')
    {
        argv[5][i] = '4';
    }
	else if (argv[0][i] == '3' && argv[1][i] == '1')
	{
		argv[7][i] = '4';
	}
	else if (argv[0][i] == '1' && argv[1][i] == '3')
	{
		argv[4][i] = '4';
	}
}

void	paterns_2_1(char **argv, int i)
{
	if (argv[0][i] == '2' && argv[1][i] == '1')
	{
		argv[7][i] = '4';
		argv[4][i] = '3';
	}
	else if (argv[0][i] == '1' && argv[1][i] == '2')
	{
		argv[4][i] = '4';
		argv[7][i] = '3';
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Converts a number into its literal value.                              */
/*   • ./a.out ([ dictionnary ]) [ number ]                                   */
/*      -> dictionnary   [ en, fr ]                                           */
/*      -> number        [ -10^39 < x < +10^39 ]                              */
/*        -> ft_error, ft_strdup, ft_strtolower, ft_strcmp                    */
/*        -> free                                                             */
/* ************************************************************************** */
#include "includes/main.h"

// ----------------------PROTOTYPE------------------------
int		main(int argc, char **argv);
int		ft_init(char **filename, char *nb);
void	ft_get_dict(char **filename, int *filename_flg);
void	ft_select_dict(char **filename, char *lw_filename,
		char *dict, int *filename_flg);
// -------------------------------------------------------

int	main(int argc, char **argv)
{
	char	*filename;

	if (argc == 2)
	{
		filename = ft_strdup("Dictionnaries/englishUS.dict");
		if (ft_init(&filename, argv[1]) == -1)
			ft_error();
		free(filename);
	}
	else if (argc == 3)
	{
		filename = ft_strdup(argv[1]);
		if (ft_init(&filename, argv[2]) == -1)
			ft_error();
		free(filename);
	}
	else
		ft_error();
	return (0);
}

int	ft_init(char **filename, char *nb)
{
	char	*f_nb;
	int		sign;
	int		filename_flg;

	f_nb = 0;
	sign = 0;
	filename_flg = 0;
	ft_get_dict(filename, &filename_flg);
	if (!*filename)
		return (-1);
	if (ft_check_format(nb, &f_nb, &sign) == -1)
		return (-1);
	if (ft_dict(*filename, f_nb, &sign, &filename_flg) == -1)
	{
		free(f_nb);
		return (-1);
	}
	free(f_nb);
	return (0);
}

void	ft_get_dict(char **filename, int *filename_flg)
{
	char	*lw_filename;
	char	*dict;

	lw_filename = ft_strtolower(*filename);
	dict = NULL;
	if (ft_strcmp(lw_filename, "dictionnaries/englishus.dict") == 0
		|| ft_strcmp(lw_filename, "english") == 0
		|| ft_strcmp(lw_filename, "en") == 0
		|| ft_strcmp(lw_filename, "us") == 0)
	{
		*filename_flg = 1;
		dict = "Dictionnaries/englishUS.dict";
	}
	else if (ft_strcmp(lw_filename, "dictionnaries/french.dict") == 0
		|| ft_strcmp(lw_filename, "french") == 0
		|| ft_strcmp(lw_filename, "fr") == 0)
	{
		*filename_flg = 2;
		dict = "Dictionnaries/french.dict";
	}
	ft_select_dict(filename, lw_filename, dict, filename_flg);
	return ;
}

void	ft_select_dict(char **filename, char *lw_filename, char *dict, int *filename_flg)
{
	if (dict == NULL && (ft_strcmp(lw_filename, "dictionnaries/spanish.dict") == 0
		|| ft_strcmp(lw_filename, "spanish") == 0
		|| ft_strcmp(lw_filename, "es") == 0))
	{
		*filename_flg = 3;
		dict = "Dictionnaries/spanish.dict";
	}
	free(lw_filename);
	if (dict)
	{
		free(*filename);
		*filename = ft_strdup(dict);
	}
	else
	{
		free(*filename);
		*filename = NULL;
	}
	return ;
}

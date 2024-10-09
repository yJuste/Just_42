/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-06.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Functions for accessing dictionary values.                    PART 2   */
/*        -> ft_isdigit, ft_isspace, ft_isprint, ft_strjoin                   */
/*        -> malloc                                                           */
/* ************************************************************************** */
#include "includes/main.h"

// --------------------PROTOTYPE--------------------
void	ft_equivalent(t_num *_num, char *line);
void	ft_join_equivalent(t_num *_num, char **str);
void	ft_tiret(t_num *_num);
// -------------------------------------------------

void	ft_equivalent(t_num *_num, char *line)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	j = 0;
	while (ft_isdigit(line[i]))
		i++;
	while (ft_isspace(line[i]))
		i++;
	i++;
	while (ft_isspace(line[i]))
		i++;
	j = i;
	while (ft_isprint(line[j]))
		j++;
	str = ft_malloc(sizeof(char) * (j - i) + 1);
	k = 0;
	while (i < j)
		str[k++] = line[i++];
	str[k] = '\0';
	ft_join_equivalent(_num, &str);
	return ;
}

void	ft_join_equivalent(t_num *_num, char **str)
{
	_num->final_nb = ft_strjoin(_num->final_nb, *str);
	_num->final_nb = ft_strjoin(_num->final_nb, " ");
	free(*str);
	return ;
}

void	ft_tiret(t_num *_num)
{
	char	*chr;

	if (_num->final_nb && _num->final_nb[ft_strlen(_num->final_nb) - 1] == ' ')
		_num->final_nb[ft_strlen(_num->final_nb) - 1] = '\0';
	chr = "-";
	_num->final_nb = ft_strjoin(_num->final_nb, chr);
	return ;
}

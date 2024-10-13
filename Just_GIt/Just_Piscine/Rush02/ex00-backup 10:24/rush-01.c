/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Check the validity of the number.                                      */
/*        -> ft_isdigit, ft_calloc, ft_strdup                                 */
/*        -> free                                                             */
/* ************************************************************************** */
#include "includes/main.h"

// ---------------------------PROTOTYPE---------------------------
int		ft_check_format(char *nb, char **f_nb, int *sign);
int		ft_check_sign(char *nb, int *sign);
int		ft_check_number(char *nb);
int		ft_trim_space(char *nb, char **f_nb, int f_sign);
char	*ft_trim_zero(char *nb);
// ---------------------------------------------------------------

int	ft_check_format(char *nb, char **f_nb, int *sign)
{
	int		f_sign;
	char	*tr_f_nb;

	if (nb[0] == '\0')
		return (-1);
	f_sign = ft_check_sign(nb, sign);
	if (f_sign == -1)
		return (-1);
	if (ft_check_number(nb) == -1)
		return (-1);
	ft_trim_space(nb, f_nb, f_sign);
	tr_f_nb = ft_trim_zero(*f_nb);
	if (tr_f_nb == NULL)
	{
		free(*f_nb);
		return (-1);
	}
	free(*f_nb);
	*f_nb = tr_f_nb;
	return (0);
}

int	ft_check_sign(char *nb, int *sign)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (nb[i] == ' ')
		i++;
	if (nb[i] == '+' || nb[i] == '-')
	{
		if (nb[i] == '-')
			(*sign)++;
		i++;
	}
	j = i;
	while (nb[j] == ' ')
		j++;
	if (nb[j] == '\0' || !ft_isdigit(nb[j]))
		return (-1);
	while (ft_isdigit(nb[j]))
		j++;
	while (nb[j] == ' ')
		j++;
	if (nb[j] != '\0')
		return (-1);
	return (i);
}

int	ft_check_number(char *nb)
{
	int	i;

	i = 0;
	while (nb[i] == ' ')
		i++;
	while (nb[i])
	{
		if (nb[i] == ' ')
		{
			while (nb[i] == ' ')
				i++;
			if (nb[i] == '\0')
				return (0);
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_trim_space(char *nb, char **f_nb, int f_sign)
{
	int	i;
	int	j;

	i = f_sign;
	j = 0;
	while (nb[i])
	{
		if (nb[i] != ' ')
			j++;
		i++;
	}
	*f_nb = ft_calloc(sizeof(char), j + 1);
	i = f_sign;
	j = 0;
	while (nb[i])
	{
		if (nb[i] != ' ')
		{
			(*f_nb)[j] = nb[i];
			j++;
		}
		i++;
	}
	(*f_nb)[j] = '\0';
	return (0);
}

char	*ft_trim_zero(char *nb)
{
	int	i;

	i = 0;
	while (nb[i] == '0')
		i++;
	if (nb[i] == '\0')
		return (ft_strdup("0"));
	return (ft_strdup(&nb[i]));
}

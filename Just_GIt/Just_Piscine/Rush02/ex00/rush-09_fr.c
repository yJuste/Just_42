/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-08.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • The literal number algorithm.                            FR - PART 1   */
/*        -> ft_strlen                                                        */
/*        -> malloc, buffer                                                   */
/* ************************************************************************** */
#include "includes/main.h"

// ---------------------------PROTOTYPE----------------------------
void	ft_separate_fr(char ***separated, char *nb);
void	ft_alloc_str_fr(char ***str);
void	ft_trio_fr(t_sep *_sep, char **str, char *nb);
void	ft_get_2_digits_fr(t_sep *_sep, char **str, char *nb);
void	ft_get_2_digits_next_fr(t_sep *_sep, char **str, char *nb);
// ----------------------------------------------------------------

void	ft_separate_fr(char ***separated, char *nb)
{
	t_sep	_sep;

	_sep.cooldown = 0;
	_sep.xi = 0;
	_sep.xj = 0;
	_sep.xnb = 0;
	_sep.len = ft_strlen(nb) % 3;
	_sep.len_A = ft_strlen(nb);
	ft_alloc_str_fr(&*separated);
	if (!*separated)
		return ;
	if (ft_strlen(nb) >= 40)
		return ;
	if (_sep.len == 0)
		_sep.len = 3;
	while (_sep.len_A > 0)
	{
		if (_sep.len >= 1 && _sep.len <= 3)
			ft_trio_fr(&_sep, *separated, nb);
		_sep.len_A -= 3;
	}
	return ;
}

void	ft_alloc_str_fr(char ***arr)
{
	int	i;

	i = 0;
	*arr = (char **)malloc(sizeof(char *) * BUFFER_SEP);
	if (*arr == NULL)
		return ;
	while (i < BUFFER_SEP)
	{
		(*arr)[i] = (char *)malloc(sizeof(char) * 40);
		if ((*arr)[i] == NULL)
			return ;
		i++;
	}
	(*arr)[i] = NULL;
	return ;
}

void	ft_trio_fr(t_sep *_sep, char **str, char *nb)
{
	_sep->cooldown = 0;
	while (_sep->len != 0)
	{
		if (_sep->len == 1)
		{
			ft_get_digit_fr(_sep, str, nb);
			_sep->xnb++;
			_sep->len--;
		}
		else if (_sep->len == 2)
		{
			ft_get_2_digits_fr(_sep, str, nb);
			_sep->len -= 2;
		}
		else if (_sep->len == 3)
		{
			ft_get_digit_fr(_sep, str, nb);
			ft_get_100_fr(_sep, str, nb);
		}
	}
	_sep->len = 3;
	if (!_sep->cooldown)
		ft_get_power_fr(_sep, str);
	return ;
}

void	ft_get_2_digits_fr(t_sep *_sep, char **str, char *nb)
{
	if (nb[_sep->xnb] == '0')
	{
		if (nb[_sep->xnb + 1] == '0')
		{
			_sep->xnb += 2;
			return ;
		}
		str[_sep->xj][_sep->xi] = nb[_sep->xnb + 1];
		str[_sep->xj][_sep->xi + 1] = '\0';
	}
	ft_get_2_digits_next_fr(_sep, str, nb);
	return ;
}

void	ft_get_2_digits_next_fr(t_sep *_sep, char **str, char *nb)
{
	if (nb[_sep->xnb] == '1')
	{
		str[_sep->xj][_sep->xi] = nb[_sep->xnb];
		str[_sep->xj][_sep->xi + 1] = nb[_sep->xnb + 1];
		str[_sep->xj][_sep->xi + 2] = '\0';
	}
	else if (nb[_sep->xnb] >= '2' && nb[_sep->xnb] <= '9')
	{
		str[_sep->xj][_sep->xi] = nb[_sep->xnb];
		str[_sep->xj][_sep->xi + 1] = '0';
		str[_sep->xj][_sep->xi + 2] = '\0';
		if (nb[_sep->xnb + 1] != '0')
		{
			_sep->xj++;
			str[_sep->xj][_sep->xi] = '|';
			_sep->xj++;
			str[_sep->xj][_sep->xi] = nb[_sep->xnb + 1];
			str[_sep->xj][_sep->xi + 1] = '\0';
		}
	}
	_sep->xnb += 2;
	_sep->xj++;
	return ;
}

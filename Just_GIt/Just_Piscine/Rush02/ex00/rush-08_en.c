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
/*   • The literal number algorithm.                            EN - PART 2   */
/*        -> ft_strcpy                                                        */
/* ************************************************************************** */
#include "includes/main.h"

// ----------------------PROTOTYPE------------------------
void	ft_get_digit(t_sep *_sep, char **str, char *nb);
void	ft_get_100(t_sep *_sep, char **str, char *nb);
void	ft_get_power(t_sep *_sep, char **str);
void	ft_get_power_2(t_sep *_sep, char **str, int *flg);
void	ft_get_power_3(t_sep *_sep, char **str, int *flg);
// -------------------------------------------------------

void	ft_get_digit(t_sep *_sep, char **str, char *nb)
{
	if (nb[_sep->xnb] == '0')
	{
		if (nb[_sep->xnb + 1] == '\0')
		{
			str[_sep->xj][_sep->xi] = '0';
			str[_sep->xj][_sep->xi + 1] = '\0';
			_sep->xj++;
			return ;
		}
		_sep->xi = 0;
		return ;
	}
	str[_sep->xj][_sep->xi] = nb[_sep->xnb];
	str[_sep->xj][_sep->xi + 1] = '\0';
	_sep->xi = 0;
	_sep->xj++;
	return ;
}

void	ft_get_100(t_sep *_sep, char **str, char *nb)
{
	if (nb[_sep->xnb] == '0' && nb[_sep->xnb + 1] == '0' && nb[_sep->xnb + 2] == '0')
	{
		_sep->cooldown = 1;
		_sep->xnb += 3;
		_sep->len -= 3;
		return ;
	}
	if (nb[_sep->xnb] != '0')
	{
		ft_strcpy(str[_sep->xj], "100");
		_sep->xj++;
		_sep->len--;
		_sep->xnb++;
		return ;
	}
	_sep->len--;
	_sep->xnb++;
	return ;
}

void	ft_get_power(t_sep *_sep, char **str)
{
	int	flg;

	flg = 0;
	if (_sep->len_A >= 4 && _sep->len_A <= 6)
	{
		ft_strcpy(str[_sep->xj], "1000");
		flg = 1;
	}
	else if (_sep->len_A >= 7 && _sep->len_A <= 9)
	{
		ft_strcpy(str[_sep->xj], "1000000");
		flg = 1;
	}
	else if (_sep->len_A >= 10 && _sep->len_A <= 12)
	{
		ft_strcpy(str[_sep->xj], "1000000000");
		flg = 1;
	}
	else if (_sep->len_A >= 13 && _sep->len_A <= 15)
	{
		ft_strcpy(str[_sep->xj], "1000000000000");
		flg = 1;
	}
	ft_get_power_2(_sep, str, &flg);
	return ;
}

void	ft_get_power_2(t_sep *_sep, char **str, int *flg)
{
	if (_sep->len_A >= 16 && _sep->len_A <= 18)
	{
		ft_strcpy(str[_sep->xj], "1000000000000000");
		*flg = 1;
	}
	else if (_sep->len_A >= 19 && _sep->len_A <= 21)
	{
		ft_strcpy(str[_sep->xj], "1000000000000000000");
		*flg = 1;
	}
	else if (_sep->len_A >= 22 && _sep->len_A <= 24)
	{
		ft_strcpy(str[_sep->xj], "1000000000000000000000");
		*flg = 1;
	}
	else if (_sep->len_A >= 25 && _sep->len_A <= 27)
	{
		ft_strcpy(str[_sep->xj], "1000000000000000000000000");
		*flg = 1;
	}
	ft_get_power_3(_sep, str, flg);
	return ;
}

void	ft_get_power_3(t_sep *_sep, char **str, int *flg)
{
	if (_sep->len_A >= 28 && _sep->len_A <= 30)
	{
		ft_strcpy(str[_sep->xj], "1000000000000000000000000000");
		*flg = 1;
	}
	else if (_sep->len_A >= 31 && _sep->len_A <= 33)
	{
		ft_strcpy(str[_sep->xj], "1000000000000000000000000000000");
		*flg = 1;
	}
	else if (_sep->len_A >= 34 && _sep->len_A <= 36)
	{
		ft_strcpy(str[_sep->xj], "1000000000000000000000000000000000");
		*flg = 1;
	}
	else if (_sep->len_A >= 37 && _sep->len_A <= 39)
	{
		ft_strcpy(str[_sep->xj], "1000000000000000000000000000000000000");
		*flg = 1;
	}
	if (*flg == 1)
		_sep->xj++;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-07.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • The literal number algorithm.                            EN - PART 1   */
/*        -> ft_strlen                                                        */
/*        -> malloc, buffer                                                   */
/* ************************************************************************** */
#include "includes/main.h"

// --------------------------PROTOTYPE--------------------------
void	ft_separate(char ***separated, char *nb);
void	ft_alloc_str(char ***str);
void	ft_trio(t_sep *_sep, char **str, char *nb);
void	ft_get_2_digits(t_sep *_sep, char **str, char *nb);
void	ft_get_2_digits_next(t_sep *_sep, char **str, char *nb);
// -------------------------------------------------------------

void	ft_separate(char ***separated, char *nb)
{
	t_sep	_sep;

	_sep.cooldown = 0;
	_sep.xi = 0;
	_sep.xj = 0;
	_sep.xnb = 0;
	_sep.len = ft_strlen(nb) % 3;
	_sep.len_total = ft_strlen(nb);
	ft_alloc_str(&*separated);
	if (!*separated)
		return ;
	if (ft_strlen(nb) >= 40)
		return ;
	if (_sep.len == 0)
		_sep.len = 3;
	while (_sep.len_total > 0)
	{
		if (_sep.len >= 1 && _sep.len <= 3)
			ft_trio(&_sep, *separated, nb);
		_sep.len_total -= 3;
	}
	return ;
}

void	ft_alloc_str(char ***arr)
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

void	ft_trio(t_sep *_sep, char **str, char *nb)
{
	_sep->cooldown = 0;
	while (_sep->len != 0)
	{
		if (_sep->len == 1)
		{
			ft_get_digit(_sep, str, nb);
			_sep->xnb++;
			_sep->len--;
		}
		else if (_sep->len == 2)
		{
			ft_get_2_digits(_sep, str, nb);
			_sep->len -= 2;
		}
		else if (_sep->len == 3)
		{
			ft_get_digit(_sep, str, nb);
			ft_get_100(_sep, str, nb);
		}
	}
	_sep->len = 3;
	if (!_sep->cooldown)
		ft_get_power(_sep, str);
	return ;
}

void	ft_get_2_digits(t_sep *_sep, char **str, char *nb)
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
	ft_get_2_digits_next(_sep, str, nb);
	return ;
}

void	ft_get_2_digits_next(t_sep *_sep, char **str, char *nb)
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

/*	-------------------------Bonus----------------------------
	---------- displays the sub-numbers of the num. ----------
	----------------------------------------------------------

int	main(int argc, char **argv)
{
	int	i;
	char	**separated;
	
	if (argc != 2)
		return (1);
	ft_separate(&separated, argv[1]); // the algorithm is called here
	if (separated != NULL)
	{
		i = 0;
		while (separated[i] != NULL)
		{
			printf("%s,", separated[i]);
			i++;
		}
		printf("\n");
		ft_free_str(separated);
	}
	else
	{
		printf("Erreur dans le traitement.\n");
	}
	return 0;
}
*/

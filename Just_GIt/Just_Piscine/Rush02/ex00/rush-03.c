/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Start analysis to display the number.                                  */
/*        -> ft_get_next_line                                                 */
/*        -> free, open                                                       */
/* ************************************************************************** */
#include "includes/main.h"

// -------------------------PROTOTYPE------------------------
int		ft_equivalent_init(t_num *_num, char **line);
int		ft_open_fd(t_num *_num);
void	ft_flg(t_num *_num, char **line);
void	ft_add_tiret(t_num *_num);
int		ft_take_number_dict(t_num *_num, char **line);
// -----------------------------------------------------------

int	ft_equivalent_init(t_num *_num, char **line)
{
	if (ft_open_fd(_num) == -1)
		return (-1);
	ft_flg(_num, line);
	return (0);
}

int	ft_open_fd(t_num *_num)
{
	_num->fd = open(_num->filename, O_RDONLY);
	if (_num->fd < 0)
		return (-1);
	return (0);
}

void	ft_flg(t_num *_num, char **line)
{
	if (_num->flg == 0)
	{
		*line = ft_get_next_line(_num->fd);
		_num->flg = 1;
	}
	return ;
}

void	ft_add_tiret(t_num *_num)
{
	_num->index++;
	ft_tiret(_num);
	return ;
}

int	ft_take_number_dict(t_num *_num, char **line)
{
	_num->tmp = ft_number_dict(*line);
	if (_num->tmp == NULL)
	{
		free(*line);
		return (-1);
	}
	return (0);
}

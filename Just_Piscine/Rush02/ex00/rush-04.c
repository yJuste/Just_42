/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • End of analysis to display the number.                                 */
/*        -> ft_get_next_line                                                 */
/*        -> free, close                                                      */
/* ************************************************************************** */
#include "includes/main.h"

// -----------------------PROTOTYPE-----------------------
void	ft_correct_comp(t_num *_num, char **line);
int		ft_error_line(char **line);
void	ft_parse_next_line(t_num *_num, char **line);
void	ft_close_fd(t_num *_num);
int		ft_print_result(t_num *_num, char **line);
// -------------------------------------------------------

void	ft_correct_comp(t_num *_num, char **line)
{
	ft_equivalent(_num, *line);
	free(_num->tmp);
	return ;
}

int	ft_error_line(char **line)
{
	free(*line);
	return (-1);
}

void	ft_parse_next_line(t_num *_num, char **line)
{
	free(*line);
	*line = ft_get_next_line(_num->fd);
	return ;
}

void	ft_close_fd(t_num *_num)
{
	close(_num->fd);
	_num->index++;
	return ;
}

int	ft_print_result(t_num *_num, char **line)
{
	free(*line);
	ft_append_sign(_num);
	ft_print_final_nb(_num);
	return (0);
}

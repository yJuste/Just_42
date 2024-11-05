/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Analyzes and displays the literal number.                              */
/*        -> ft_strcmp, ft_putstr, ft_putchar                                 */
/*        -> malloc, free                                                     */
/* ************************************************************************** */
#include "includes/main.h"

// ----------------------------------PROTOTYPE----------------------------------
int		ft_dict(char *filename, char **nb, int *sign, int *filename_flg);
int		ft_dict_init(t_num *_num, char ***sub_numbers);
int		ft_print_equivalent(t_num *_num, char **sub_numbers, char *line);
void	ft_append_sign(t_num *_num);
void	ft_print_final_nb(t_num *_num);
// -----------------------------------------------------------------------------

int	ft_dict(char *filename, char **nb, int *sign, int *filename_flg)
{
	char	**sub_numbers;
	char	*line;
	t_num	_num;

	_num.filename = filename;
	_num.nb = *nb;
	_num.sign = *sign;
	_num.filename_flg = *filename_flg;
	line = NULL;
	sub_numbers = NULL;
	if (ft_strlen(*nb) >= 40)
		return (-1);
	if (ft_dict_init(&_num, &sub_numbers) == -1)
		return (-1);
	if (ft_print_equivalent(&_num, sub_numbers, line) == -1)
	{
		ft_free_str(sub_numbers);
		return (-1);
	}
	ft_free_str(sub_numbers);
	return (0);
}

/* add in line 9-10, for another language.
if (_num->filename_flg == 2)
	ft_separate_fr(sub_numbers, _num->nb);
*/
int	ft_dict_init(t_num *_num, char ***sub_numbers)
{
	_num->final_nb = ft_malloc(sizeof(char) * 1);
	_num->final_nb[0] = '\0';
	_num->index = 0;
	_num->fd = 0;
	_num->sign_flg = 0;
	_num->flg = 0;
	_num->tmp = 0;
	if (_num->filename_flg == 1)
		ft_separate(sub_numbers, _num->nb);
	else
	{
		free(_num->final_nb);
		return (-1);
	}
	if (*sub_numbers == NULL)
	{
		free(_num->final_nb);
		return (-1);
	}
	return (0);
}

int	ft_print_equivalent(t_num *_num, char **sub_numbers, char *line)
{
	while (sub_numbers[_num->index] != NULL)
	{
		ft_equivalent_init(_num, &line);
		while (line != NULL)
		{
			if (ft_check_line_format(line) == 0)
			{
				if (ft_strcmp(sub_numbers[_num->index], "|") == 0)
					ft_add_tiret(_num);
				if (ft_take_number_dict(_num, &line) == -1)
					return (-1);
				if (ft_strcmp(sub_numbers[_num->index], _num->tmp) == 0)
				{
					ft_correct_comp(_num, &line);
					break ;
				}
				free(_num->tmp);
			}
			else
				return (ft_error_line(&line));
			ft_parse_next_line(_num, &line);
		}
		ft_close_fd(_num);
	}
	return (ft_print_result(_num, &line));
}

void	ft_append_sign(t_num *_num)
{
	if (_num->sign_flg == 0)
	{
		if (_num->sign % 2 != 0)
		{
			if (_num->filename_flg == 1)
				ft_putstr("minus ");
			if (_num->filename_flg == 2)
				ft_putstr("moins ");
		}
		_num->sign_flg = 1;
	}
	return ;
}

void	ft_print_final_nb(t_num *_num)
{
	int	i;

	i = 0;
	while (_num->final_nb[i])
		i++;
	if (i > 0 && _num->final_nb[i - 1] == ' ')
		_num->final_nb[i - 1] = '\0';
	i = 0;
	while (_num->final_nb[i])
	{
		ft_putchar(_num->final_nb[i]);
		i++;
	}
	ft_putchar('\n');
	free(_num->final_nb);
	return ;
}

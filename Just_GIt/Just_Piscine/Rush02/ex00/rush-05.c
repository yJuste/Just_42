/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-05.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Functions for accessing dictionary values.                    PART 1   */
/*        -> ft_isdigit, ft_isspace, ft_isprint                               */
/*        -> malloc                                                           */
/* ************************************************************************** */
#include "includes/main.h"

// ----------------------PROTOTYPE------------------------
int		ft_check_line_format(char *line);
int		ft_check_line_format_2(char *line, int i);
char	*ft_number_dict(char *line);
int		ft_len_dict_number(char *line);
// -------------------------------------------------------

int	ft_check_line_format(char *line)
{
	int	i;
	int	digit;

	i = 0;
	digit = 0;
	if (line[i] == '\n')
		return (-1);
	while (ft_isdigit(line[i]))
	{
		i++;
		digit = 1;
	}
	if (!digit)
		return (-1);
	while (ft_isspace(line[i]))
		i++;
	if (line[i] != ':')
		return (-1);
	i++;
	return (ft_check_line_format_2(line, i));
}

int	ft_check_line_format_2(char *line, int i)
{
	while (ft_isspace(line[i]))
		i++;
	if (!ft_isprint(line[i]))
		return (-1);
	while (ft_isprint(line[i]))
		i++;
	if (line[i] != '\n')
		return (-1);
	return (0);
}

char	*ft_number_dict(char *line)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * ft_len_dict_number(line) + 1);
	if (!dest)
		return (NULL);
	while (line[i] && !ft_isspace(line[i]) && line[i] != ':')
	{
		dest[i] = line[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_len_dict_number(char *line)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (line[i] && !ft_isspace(line[i]) && line[i] != ':')
	{
		len++;
		i++;
	}
	return (len);
}

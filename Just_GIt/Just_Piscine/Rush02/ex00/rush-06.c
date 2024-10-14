/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-06.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Functions for accessing dictionary values.                    PART 2   */
/*        -> ft_isdigit, ft_isspace, ft_isprint, ft_strjoin                   */
/*        -> malloc, buffer, read                                             */
/*        -> Bonus - line 75                                                  */
/* ************************************************************************** */
#include "includes/main.h"

// --------------------PROTOTYPE--------------------
void	ft_equivalent(t_num *_num, char *line);
void	ft_join_equivalent(t_num *_num, char **str);
void	ft_tiret(t_num *_num);

char	*ft_read(const char *message, const char *default_vle);
char	*ft_read_get_default(const char *default_vle);
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

/*	------------------------------Bonus------------------------------
	--------- Allows the program to run without arguments. ----------
	---------     Used in the main.c but I had no room.    ----------
	---------                      ._.                     ----------
	-----------------------------------------------------------------*/

char	*ft_read(const char *message, const char *default_vle)
{
	char		buffer[42];
	size_t		len;

	write(STDOUT_FILENO, message, ft_strlen(message));
	len = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
	if (len >= sizeof(buffer))
		return (NULL);
	if (len >= 0 && buffer[len - 1] == '\n')
		buffer[len - 1] = '\0';
	if (buffer[0] == '\0')
		return (ft_read_get_default(default_vle));
	return (ft_strdup(buffer));
}

char	*ft_read_get_default(const char *default_vle)
{
	char		*default_cpy;

	if (default_vle != NULL)
	{
		if (default_vle[ft_strlen(default_vle) - 1] == '\n')
		{
			default_cpy = ft_strdup(default_vle);
			default_cpy[ft_strlen(default_cpy) - 1] = '\0';
		}
		else
			default_cpy = ft_strdup(default_vle);
		return (default_cpy);
	}
	return (NULL);
}

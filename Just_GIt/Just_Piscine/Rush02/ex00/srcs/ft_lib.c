/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • First Library.                                                         */
/* ************************************************************************** */
#include "../includes/main.h"

// --------------PROTOTYPE-----------------
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(const char *str);
int		ft_error(void);
void	ft_free_str(char **str);
// ----------------------------------------

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_error(void)
{
	ft_putstr("Dict Error\n");
	return (-1);
}

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return;
	while (i < BUFFER_SEP + 1)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

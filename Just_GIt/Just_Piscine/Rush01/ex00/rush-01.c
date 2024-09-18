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
/*   • Check the validity of the clues and the size.                          */
/*        -> ft_atoi, ft_isdigit, ft_strlen                                   */
/*        -> malloc, free                                                     */
/* ************************************************************************** */
#include "main.h"

// ------------------------PROTOTYPE-----------------------------
int		ft_dimensions(char *str);
int		ft_format(char *str, int size);
int		ft_check_format(char *str, int *count);
int		*ft_create_format(char *str, int *tab, int size);
void	ft_print_format(int *tab, int size);
// --------------------------------------------------------------

int	ft_dimensions(char *str)
{
	int	size;

	size = ft_atoi(str);
	if (size <= 0)
		return (-1);
	if (!ft_isdigit(*str))
		return (-1);
	str++;
	if (*str != '\0')
		return (-1);
	return (size);
}

//	---BONUS--- line 14 to 15
//	ft_print_format(tab, count);
int	ft_format(char *str, int size)
{
	int	*tab;
	int	count;

	count = 0;
	if (ft_check_format(str, &count) == -1)
		return (-1);
	if (ft_strlen(str) != (size * 4) * 2 - 1)
		return (-1);
	tab = malloc(sizeof(int) * (count + 1));
	if (tab == NULL)
		return (-1);
	if (ft_create_format(str, tab, size) == NULL )
		return (-1);
	if (ft_grid(tab, size) == -1)
		return (-1);
	return (0);
}

int	ft_check_format(char *str, int *count)
{
	*count = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			(*count)++;
			str++;
		}
		else
			return (-1);
		if (*str == ' ')
			str++;
		else if (*str != '\0')
			return (-1);
	}
	return (0);
}

int	*ft_create_format(char *str, int tab[], int size)
{
	int	nb;
	int	i;

	i = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			nb = ft_atoi(str);
			if (nb < 1 || nb > size)
			{
				free(tab);
				return (NULL);
			}
			tab[i++] = nb;
			str++;
		}
		else if (*str == ' ')
			str++;
	}
	tab[i] = 0;
	return (tab);
}

/*	--------------------Bonus-----------------------
	--- displays the grid entered in parameters. ---
	------------------------------------------------

void	ft_print_format(int tab[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
	ft_putchar('\n');
}
*/

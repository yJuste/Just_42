/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/main.h"

// ---------PROTOTYPE-----------
int		ft_error(void);
void	ft_free_str(char **str);
// -----------------------------

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

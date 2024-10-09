/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/main.h"

// ---------PROTOTYPE-------------
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_tolower(int c);
char	*ft_strtolower(char *str);
// -------------------------------

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char	*ft_strtolower(char *str)
{
	int		i;
	char	*lwr_str;

	i = 0;
	if (!str)
		return (NULL);
	lwr_str = ft_strdup(str);
	if (!lwr_str)
		return (NULL);
	while (lwr_str[i])
	{
		lwr_str[i] = ft_tolower(lwr_str[i]);
		i++;
	}
	return (lwr_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int argc, char **argv);
char				*ft_strdup(const char *src);
size_t				ft_strlen(const char *str);

struct s_stock_str	*ft_strs_to_tab(int argc, char **argv)
{
	int			i;
	t_stock_str	*_stock_str;

	i = 0;
	_stock_str = malloc(sizeof(t_stock_str) * (argc + 1));
	if (_stock_str == NULL)
		return (NULL);
	while (i < argc)
	{
		_stock_str[i].size = ft_strlen(argv[i]);
		_stock_str[i].str = argv[i];
		_stock_str[i].copy = ft_strdup(argv[i]);
		i++;
	}
	_stock_str[i].str = 0;
	return (_stock_str);
}

char	*ft_strdup(const char *src)
{
	size_t		i;
	char		*dst;

	i = 0;
	if (src == NULL)
		return (NULL);
	dst = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (dst == NULL)
		return (NULL);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

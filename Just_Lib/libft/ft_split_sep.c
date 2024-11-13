/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Returns an arr of arr defined by a separator.                          */
/*   • Prototype:   CHAR ** ( char *, char * )                                */
/*        -> malloc, size_t                                                   */
/* ************************************************************************** */
#include "just_lib.h"

static char	*ft_strdup_sep_split(char *src, int start, int end);
static int	ft_is_sep_split(char c, char *charset);

char	**ft_split_sep(char *str, char *charset)
{
	char		**res;
	int			start;
	int			substr;
	int			i;

	i = 0;
	start = 0;
	substr = 0;
	res = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	while (str[i])
	{
		while (str[i] && ft_is_sep_split(str[i], charset))
			i++;
		start = i;
		while (str[i] && !ft_is_sep_split(str[i], charset))
			i++;
		if (start < i)
		{
			res[substr] = ft_strdup_sep_split(str, start, i);
			substr++;
		}
	}
	res[substr] = NULL;
	return (res);
}

static char	*ft_strdup_sep_split(char *src, int start, int end)
{
	char		*res;
	int			i;

	res = malloc(sizeof(char) * (end - start + 1));
	i = 0;
	while (i < end - start)
	{
		res[i] = src[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int	ft_is_sep_split(char c, char *charset)
{
	size_t		i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

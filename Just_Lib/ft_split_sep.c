/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
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
#include <stdlib.h>

char	**ft_split(char *str, char *charset);
char	*ft_strdup_split(char *src, int start, int end);
int		ft_is_sep(char c, char *charset);
size_t	ft_strlen(const char *str);

char	**ft_split(char *str, char *charset)
{
	char		**res;
	int			start;
	int			substr;
	int		i;

	i = 0;
	start = 0;
	substr = 0;
	res = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	while (str[i])
	{
		while (str[i] && ft_is_sep(str[i], charset))
			i++;
		start = i;
		while (str[i] && !ft_is_sep(str[i], charset))
			i++;
		if (start < i)
		{
			res[substr] = ft_strdup_split(str, start, i);
			substr++;
		}
	}
	res[substr] = NULL;
	return (res);
}

char	*ft_strdup_split(char *src, int start, int end)
{
	char		*res;
	int		i;

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

int	ft_is_sep(char c, char *charset)
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

size_t	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
/*   • Returns an arr of arr defined by spaces.                               */
/*   • Prototype:   CHAR ** ( char * )                                        */
/*        -> malloc, size_t                                                   */
/* ************************************************************************** */
#include <stdlib.h>

char	**ft_split(char *str);
int		ft_split_word_count(char *str);
char	*ft_strncpy(char *dest, const char *src, size_t n);

// attention : pas de gestion d'erreur de malloc
char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**str_split;

	i = 0;
	j = 0;
	k = 0;
	str_split = malloc(sizeof(char *) * (ft_split_word_count(str) + 1));
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > j)
		{
			str_split[k] = malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(str_split[k++], &str[j], i - j);
		}
	}
	str_split[k] = NULL;
	return (str_split);
}

int	ft_split_word_count(char *str)
{
	int		i;
	int		word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			word_count++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	return (word_count);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t		i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

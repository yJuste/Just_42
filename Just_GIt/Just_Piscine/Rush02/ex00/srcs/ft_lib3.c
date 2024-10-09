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
/*   • Third Library.                                                         */
/* ************************************************************************** */
#include "../includes/main.h"

// --------------PROTOTYPE----------------
char	*ft_strdup(const char *src);
void	*ft_malloc(int size);
void	*ft_calloc(int size_of, int size);
// ---------------------------------------

char	*ft_strdup(const char *src)
{
	size_t		i;
	char		*dest;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_malloc(int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}

void	*ft_calloc(int size_of, int size)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = malloc(size_of * size);
	if (ptr == 0)
		return (NULL);
	while (i < size_of * size)
		ptr[i++] = 0;
	return (ptr);
}

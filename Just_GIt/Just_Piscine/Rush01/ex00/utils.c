/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
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

char *enleve_espace(char *str)
{
    int i;
	int j;

    // Allouer de la mémoire pour la chaîne résultante
    char *dest = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
    if (dest == NULL)
        return NULL;  // Vérifier si l'allocation a échoué

    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            dest[j] = str[i];
            j++;
        }
        i++;
    }
    dest[j] = '\0';  // Terminer la chaîne par un caractère nul
    return dest;
}

int char_to_int(char c)
{
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else {
        return -1;
    }
}

int	present_dans(char *tableau, char c)
{
	int	i;

	i = 0;
	while (tableau[i])
	{
		if (tableau[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
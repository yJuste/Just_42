/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Reallocates memory.                                                    */
/*   • Prototype:   VOID * ( void *, int, int )                               */
/*        -> malloc, free                                                     */
/* ************************************************************************** */
#include <stdlib.h>

// Don't forget to free !
// Don't forget to put sizof(..) in size .

void	*ft_calloc(size_t size)
{
	size_t		i;
	char		*ptr;

	i = 0;
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	while (i < size)
		ptr[i++] = '\0';
	return (ptr);
}

// Si tu veux raccourcir un tableau, tu dois ajouter 1 a la nouvelle taille.
// Ce sera pour le \0
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	size_t		i;
	char		*n_ptr;

	i = 0;
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	n_ptr = ft_calloc(sizeof(char) * new_size);
	if (!n_ptr)
	{
		free(ptr);
		return (NULL);
	}
	while (i < old_size && i < new_size)
	{
		n_ptr[i] = ((char *)ptr)[i];
		i++;
	}
	free(ptr);
	return (n_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Reallocates memory.                                                    */
/*   • Prototype:   VOID* ( void* ptr, int old_size, int new_size )           */
/*        -> malloc, free                                                     */
/* ************************************************************************** */
#include <stdlib.h>

// Don't forget to free !

void	*ft_calloc(int count, int size_of)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = malloc(size_of * count);
	if (ptr == 0)
		return (NULL);
	while (i < size_of * count)
		ptr[i++] = 0;
	return (ptr);
}

void	*ft_realloc(void *ptr, int old_size, int new_size)
{
	int		i;
	char	*new_ptr;

	i = 0;
	new_ptr = ft_calloc(new_size, sizeof(char));
	while (i < old_size)
	{
		new_ptr[i] = ((char *)ptr)[i];
		i++;
	}
	free(ptr);
	return (new_ptr);
}

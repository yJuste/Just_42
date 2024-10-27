/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_Memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

// 1 Ko de mémoire sur la pile
// Calcul : Memoire total (Mo) = (Profondeur de l'appel x 1024) / (1024 x 1024)
void	function(int depth)
{
	char	buffer[1024];

	printf("Profondeur de l'appel : %d", depth);
	printf("\n");
	function(depth + 1);
}

int	main(void)
{
	function(1);
	return (0);
}

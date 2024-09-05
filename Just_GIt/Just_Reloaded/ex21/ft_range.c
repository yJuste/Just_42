/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlongin <jlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 22:16:35 by jlongin           #+#    #+#             */
/*   Updated: 2024/09/04 22:16:36 by jlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	*res;

	if (min >= max)
		return (NULL);
	tab = malloc(sizeof(int) * (max - min));
	if (!tab)
		return (NULL);
	res = tab;
	while (min < max)
	{
		*tab = min;
		tab++;
		min++;
	}
	return (res);
}

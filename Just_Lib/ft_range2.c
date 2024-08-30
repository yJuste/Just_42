/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Returns all int from in start to in end.                               */
/*   • Prototype:   INT* ( int start, int end )                               */
/*        -> malloc ( sizeof(type) * size )                                   */
/*        -> size_t                                                           */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	size_t		i;
	int			len;
	int			*res;

	i = 0;
	len = end - start;
	if (len < 0)
		len = -len;
	res = (int *)malloc(sizeof(int) * (len + 1));
	while (i < len)
	{
		if (start < end)
		{
			res[i] = start;
			start++;
			i++;
		}
		else
		{
			res[i] = start;
			start--;
			i++;
		}
	}
	return (res);
}

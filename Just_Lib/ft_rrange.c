/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Returns an arr of int from max to min value.                           */
/*   • Prototype:   INT* ( int start, int end )                               */
/*        -> malloc ( sizeof(type) * size )                                   */
/*        -> size_t                                                           */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	size_t		i;
	int			flg;
	int			len;
	int			*range;

	i = 0;
	flg = 1;
	len = end - start;
	if (len < 0)
		len = -len;
	range = (int *)malloc(sizeof(int) * (len + 1));
	if (range)
	{
		if (start < end)
			flg = -1;
		while (i < len)
		{
			range[i] = end;
			end = end + flg;
			i++;
		}
	}
	return (range);
}

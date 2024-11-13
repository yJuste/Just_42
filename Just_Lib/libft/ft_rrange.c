/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Returns an arr of int from max to min value.                           */
/*   • Prototype:   INT * ( int, int )                                        */
/*        -> malloc, size_t                                                   */
/* ************************************************************************** */
#include "just_lib.h"

int	*ft_rrange(int start, int end)
{
	int			*range;
	int			flg;
	size_t		len;
	size_t		i;

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

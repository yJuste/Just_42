/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struc.h"
#include "../libs/lib_string.h"
#include "../libs/lib_arg1.h"

void	convert_number(const char *number_str, char *buffer, size_t *len)
{
	int				number_len;
	int				segment_count;
	const char		*thousands[]
		= {"", "thousand", "million", "billion", "trillion", "quadrillion",
		"quintillion", "sextillion", "septillion", "octillion", "nonillion",
		"decillion", "undecillion"};
	t_segmentData	seg_data;

	number_len = ft_strlen(number_str);
	segment_count = (number_len + 2) / 3;
	seg_data.segment_count = segment_count;
	get_segments(number_str, number_len, &seg_data);
	append_segments_to_buffer(buffer, len, &seg_data, thousands);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_seg_buffer.c                             :+:      :+:    :+:   */
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

void	append_segments_to_buffer(char *buffer, size_t *len,
			const t_segmentData *seg_data, const char *thousands[])
{
	int		i;
	char	segment_result[256];
	size_t	segment_result_len;

	i = seg_data->segment_count - 1;
	while (i >= 0)
	{
		if (seg_data->segment_lens[i] > 0)
		{
			if (*len > 0)
				append_to_buffer(buffer, len, " ");
			segment_result_len = 0;
			process_segment(ft_atoi(seg_data->segments[i]),
				segment_result, &segment_result_len, thousands[i]);
			ft_strncpy(buffer + *len, segment_result, segment_result_len);
			*len += segment_result_len;
		}
		i--;
	}
}

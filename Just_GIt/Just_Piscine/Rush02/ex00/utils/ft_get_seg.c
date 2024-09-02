/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_seg.c                                       :+:      :+:    :+:   */
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

void	get_segments(const char *number_str,
			int number_len, t_segmentData *seg_data)
{
	int	i;
	int	start_index;
	int	end_index;

	i = 0;
	while (i < seg_data->segment_count)
	{
		start_index = number_len - (i + 1) * 3;
		end_index = number_len - i * 3;
		if (start_index < 0)
			start_index = 0;
		ft_strncpy(seg_data->segments[i], &number_str[start_index],
			end_index - start_index);
		seg_data->segments[i][end_index - start_index] = '\0';
		seg_data->segment_lens[i] = ft_strlen(seg_data->segments[i]);
		i++;
	}
}

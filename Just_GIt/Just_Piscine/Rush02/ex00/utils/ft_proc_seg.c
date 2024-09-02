/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_seg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/lib_string.h"
#include "../libs/lib_arg1.h"

void	process_segment(int number, char *buffer,
			size_t *len, const char *suffix)
{
	if (number > 0)
	{
		convert_hundreds(number, buffer, len);
		if (suffix && ft_strlen(suffix) > 0)
		{
			append_to_buffer(buffer, len, " ");
			append_to_buffer(buffer, len, suffix);
		}
	}
}

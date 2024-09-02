/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUC_H
# define STRUC_H

# include <unistd.h>

typedef struct s_segmentData
{
	char	segments[256][256];
	size_t	segment_lens[256];
	int		segment_count;
}	t_segmentData;

#endif

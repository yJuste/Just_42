/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_LIST_H
# define FT_LIST_H

// Standard Library

# include <stdlib.h>

// Structure

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

// ft_create_elem.c

t_list	*ft_create_elem(void *data);

#endif

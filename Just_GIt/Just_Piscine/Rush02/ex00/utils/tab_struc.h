/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_struc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef TAB_STRUC_H
# define TAB_STRUC_H

# define BUFFER_SIZE 1024

typedef struct s_numberWords
{
	const char	*units_and_teens[20];
	const char	*tens[10];
	const char	*thousands[13];
}	t_numberWords;

void	read_file(const char *filename, t_numberWords *words);
void	initialize_and_read(const char *filename, t_numberWords *words);

#endif

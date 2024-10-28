/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_DO_OP_H
# define FT_DO_OP_H

// Standard Library

# include <unistd.h>

// ft_do_op.c

int		main(int argc, char **argv);
int		ft_do_op(char **argv);
int		ft_op(char *str);

// ft_operator.c

int		ft_add(int a, int b);
int		ft_sub(int a, int b);
int		ft_div(int a, int b);
int		ft_mult(int a, int b);
int		ft_mod(int a, int b);

// ft_lib.c

int		ft_error(int err);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putnbr(int nbr);

#endif

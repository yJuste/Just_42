/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Parses 1 char if it is printable.                                      */
/*   • Prototype:   INT ( int )                                               */
/* ************************************************************************** */
#include "just_lib.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
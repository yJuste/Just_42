/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Parses 1 char if it is a num.                                          */
/*   • Prototype:   INT ( int )                                               */
/* ************************************************************************** */

//	The 1st transcendent function.

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

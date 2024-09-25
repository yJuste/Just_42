/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Parses if it is a num.                                                 */
/*   • Prototype:   INT ( int c )                                             */
/* ************************************************************************** */

// It is an incredible function because you can pass any type of parameter as
// a char or *char, it still works and do its job.
// I like to call this function :	The 1st transcendent function.

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

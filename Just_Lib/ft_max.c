/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Finds the maximum value of an arr.                                     */
/*   • Prototype:   INT ( int *tab, int len )                                 */
/* ************************************************************************** */

int	max(int *tab, int len)
{
	int		result;
	int		i;

	i = 0;
	if (len == 0)
		return (0);
	result = tab[i];
	while (i < len)
	{
		if (result < tab[i])
			result = tab[i];
		i++;
	}
	return (result);
}

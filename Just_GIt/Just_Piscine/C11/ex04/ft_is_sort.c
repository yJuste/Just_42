/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		up;
	int		down;

	i = 0;
	up = 1;
	down = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			up = 0;
		if (f(tab[i], tab[i + 1]) > 0)
			down = 0;
		if (!up && !down)
			return (0);
		i++;
	}
	return (up || down);
}

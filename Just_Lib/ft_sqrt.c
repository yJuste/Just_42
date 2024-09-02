/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Returns the square root of a num.                                      */
/*   • Prototype:   INT ( int nbr )                                           */
/* ************************************************************************** */

// /. Only full square root.
int	ft_sqrt(int nbr)
{
	int		i;

	i = 0;
	while ((i * i) < nbr)
		i++;
	if ((i * i) == nbr)
		return (i);
	return (0);
}

// /: The square root has 2 pres digits.
//       -> 3 pres digits : l5. 0.000001 / l15. 1000, 1000
float	ft_sqrt_precise(float nbr)
{
	float		n;
	float		lg_e;
	float		res;

	lg_e = 0.0001;
	n = nbr;
	res = 0.0;
	if (nbr < 0)
		return (-1);
	while (n * n - nbr > lg_e || nbr - n * n > lg_e)
	{
		res = n;
		n = (n + nbr / n) / 2.0;
	}
	return ((res * 100 + 0.5) / 100.0);
}
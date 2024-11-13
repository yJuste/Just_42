/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Capitalizes the 1st letter of a wd.                                    */
/*   • Prototype:   CHAR * ( char * )                                         */
/*        -> size_t                                                           */
/* ************************************************************************** */
#include "just_lib.h"

char	*ft_strcapitalize(char *str)
{
	size_t		i;
	int			flg;

	i = 0;
	flg = 1;
	ft_strlowcase(str);
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (flg == 1)
				str[i] -= 32;
			flg = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			flg = 0;
		else
			flg = 1;
		i++;
	}
	return (str);
}

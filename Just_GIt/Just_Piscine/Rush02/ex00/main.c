/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libs/lib_string.h"
#include "libs/lib_arg1.h"

int	rush02(char buffer[8192], size_t buffer_len, char number_str[1024])
{
	while (number_str[0])
	{
		if (!(number_str[0] >= '0' && number_str[0] <= '9'))
		{
			ft_write("Error\n");
			break ;
		}
		else if (ft_strlen(number_str) > 31)
		{
			ft_write("Error\n");
			break ;
		}
		else
		{
			ft_write("The number in words is: ");
			convert_number(number_str, buffer, &buffer_len);
			buffer[buffer_len] = '\0';
			write(1, buffer, buffer_len);
			ft_write("\n");
			break ;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	number_str[1024];
	char	buffer[8192];
	size_t	buffer_len;

	(void) argv;
	if (argc != 1)
	{
		ft_write("Error\n");
		return (0);
	}
	buffer_len = 0;
	ft_write("Enter a number: ");
	read_number(number_str, sizeof(number_str));
	rush02(buffer, buffer_len, number_str);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by 42                                  #+#    #+#             */
/*   Updated:   by 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./ft_tail.h"

// ---------------------PROTOTYPE------------------------
void	ft_tail(t_range *_range, int fd, char *arg);
int		ft_echo(char **argv);
int		ft_read_file(char **content);

void	*ft_malloc(int size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
// ------------------------------------------------------

void	ft_tail(t_range *_range, int fd, char *arg)
{
	char		buffer[29500];
	ssize_t		b_read;
	ssize_t		total_read;
	ssize_t		to_read;

	total_read = 0;
	to_read = _range->size;
	b_read = read(fd, buffer, sizeof(buffer));
	while (b_read > 0)
	{
		total_read += b_read;
		if (total_read > to_read)
		{
			write(1, buffer + (total_read - to_read), to_read);
			return ;
		}
		write(1, buffer, b_read);
		b_read = read(fd, buffer, sizeof(buffer));
	}
	if (b_read < 0)
		ft_tail_error(-1, arg);
	return ;
}

int	ft_echo(char **argv)
{
	int		n;
	int		t_read;
	char	*content;

	n = ft_atoi(argv[2]);
	if (n < 0)
	{
		ft_tail_error(-2, "");
		return (-1);
	}
	t_read = ft_read_file(&content);
	if (t_read == -1)
	{
		ft_tail_error(-1, "");
		return (-1);
	}
	if (n > t_read)
		n = t_read;
	write(1, content + t_read - n, n);
	free(content);
	return (0);
}

int	ft_read_file(char **content)
{
	char	buffer[1024];
	char	*tmp;
	int		t_read;
	int		b_read;

	t_read = 0;
	*content = NULL;
	b_read = read(0, buffer, sizeof(buffer));
	while (b_read > 0)
	{
		tmp = ft_malloc(t_read + b_read + 1);
		if (t_read > 0)
		{
			ft_memcpy(tmp, *content, t_read);
			free(*content);
		}
		ft_memcpy(tmp + t_read, buffer, b_read);
		t_read += b_read;
		tmp[t_read] = '\0';
		*content = tmp;
		b_read = read(0, buffer, sizeof(buffer));
	}
	if (ft_error_read(b_read, content) == -1)
		return (-1);
	return (t_read);
}

// ft_lib_tail_2

void	*ft_malloc(int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*source;

	if (!dst || !src)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}

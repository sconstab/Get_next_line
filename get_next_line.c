/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 09:30:06 by sconstab          #+#    #+#             */
/*   Updated: 2019/07/03 16:41:42 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_readfile(const int fd)
{
	char	*got;
	char	*buff;

	buff = ft_strnew(BUFF_SIZE);
	got = ft_strnew(0);
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		got = ft_strjoin(got, buff);
		buff = ft_strnew(BUFF_SIZE);
	}
	return (got);
}

int	get_next_line(const int fd, char **line)
{
	static size_t	i;
	static void		*got;

	if (fd < 0 || !line || BUFF_SIZE < 0 || read(fd, NULL, 0) == -1)
		return (-1);
	if (got == NULL)
		got = ft_readfile(fd);
	while (i < (ft_wordcount(got, '\n')))
	{
		*line = ft_strcreturn(got, '\n', i);
		i++;
		return (1);
	}
	//free(line);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	int fd;
	int i;
	char *buff;

	i = 1;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while  (i > 0)
		{
			i = get_next_line(fd, &buff);
			if (i != 0)
				ft_putnbr(ft_strcmp(buff, "111"));
			free(buff);
		}
	}
	return (0);
}*/

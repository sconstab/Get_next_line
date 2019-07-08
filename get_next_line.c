/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 09:30:06 by sconstab          #+#    #+#             */
/*   Updated: 2019/07/06 05:11:24 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
 #include <fcntl.h>
     #include <sys/types.h>
     #include <sys/uio.h>
     #include <unistd.h>

static char	*ft_readfile(const int fd)
{
	char	*got;
	char	*buff;

	got = ft_strnew(0);
	buff = ft_strnew(BUFF_SIZE);
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		got = ft_strjoin(got, buff);
		buff = ft_strnew(BUFF_SIZE);
	}
	free(buff);
	return (got);
}

int			get_next_line(const int fd, char **line)
{
	static size_t	i;
	static void		*got;

	if (fd < 0 || !line || BUFF_SIZE < 0 || read(fd, NULL, 0) == -1)
		return (-1);
	if (got == NULL)
		got = ft_readfile(fd);
	while (i < (ft_wordcount(got, '\n', 1)))
	{
		*line = ft_strcreturn(got, '\n', i, 1);
		i++;
		return (1);
	}
	free(got);
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	*temp;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line))
		{
			temp = line;
			ft_putendl(line);
			if (ft_strcmp(line, "111") == 0)
				ft_putstr("Weeee Done");
			free(temp);
		}
	}
	else
	{
		fd = open("get_next_line.c", O_RDONLY);
		if (fd < 1)
			return (0);
		while (get_next_line(fd, &line))
		{
			temp = line;
			ft_putendl(line);
			free(temp);
		}
	}
	close(fd);
	return (0);
}

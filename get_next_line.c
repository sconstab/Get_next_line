/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 09:30:06 by sconstab          #+#    #+#             */
/*   Updated: 2019/07/04 16:06:56 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	while (i < (ft_wordcount(got, '\n')))
	{
		*line = ft_strcreturn(got, '\n', i);
		i++;
		return (1);
	}
	free(got);
	return (0);
}

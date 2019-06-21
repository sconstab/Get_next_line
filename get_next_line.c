/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 09:30:06 by sconstab          #+#    #+#             */
/*   Updated: 2019/06/21 06:27:40 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	size_t			r;
	static	size_t	i;
	void			*got;

	if (!i)
		i = 0;
	if (!(got = ft_memalloc(BUFF_SIZE)))
		return (-1);
	r = read(fd, got, BUFF_SIZE);
	if (!(line[i] = ft_memalloc(ft_strcnlen(got, '\n', i) * sizeof(void))))
		return (-1);
	line[i] = ft_strcreturn(got, '\n', i);
	i++;
	return (r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:52:20 by jhouston          #+#    #+#             */
/*   Updated: 2019/07/08 15:10:29 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcnlen(char const *s, char c, size_t x, bool b)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	j = 0;
	n = 0;
	if (s[i] != c || b == 1)
		j++;
	while (s[i] && j <= x)
	{
		if (s[i] == c)
		{
			while (s[i] == c && s[i] && b == 0)
				i++;
			if (s[i] && b == 1)
				i++;
			j++;
		}
		else
			while (s[i] != c && s[i])
				i++;
	}
	while (s[i++] != c && s[i])
		n++;
	return (n);
}

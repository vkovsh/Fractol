/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:00:16 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/08 14:43:57 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*buf;

	i = 0;
	c = (unsigned char)c;
	buf = (unsigned char *)s;
	while (n--)
	{
		if (*(buf + i) == c)
			return (buf + i);
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 12:55:04 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/08 13:30:44 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	c = (unsigned char)c;
	while (i++ < n)
	{
		*(s1 + i - 1) = *(s2 + i - 1);
		if (*(s2 + i - 1) == c)
			return (dst + i);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:06:09 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/08 17:22:18 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s1_end;

	if (dstsize < ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	s1_end = i;
	while (src[i - s1_end] && i < dstsize - 1)
	{
		dst[i] = src[-s1_end + i];
		i++;
	}
	if (s1_end < dstsize)
		dst[i] = '\0';
	return (s1_end + ft_strlen(src));
}

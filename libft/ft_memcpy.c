/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 12:27:44 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/08 15:12:28 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_buf;
	unsigned char	*src_buf;

	i = 0;
	dst_buf = (unsigned char *)dst;
	src_buf = (unsigned char *)src;
	while (i++ < n)
		*(dst_buf + i - 1) = *(src_buf + i - 1);
	return (dst);
}

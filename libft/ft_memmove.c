/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:03:06 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/13 13:31:55 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_buf;
	unsigned char	*src_buf;

	dst_buf = (unsigned char *)dst;
	src_buf = (unsigned char *)src;
	if (src_buf < dst_buf)
		while (len--)
			*(dst_buf + len) = *(src_buf + len);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

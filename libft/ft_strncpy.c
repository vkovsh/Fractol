/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:46:34 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/08 14:54:51 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	if (len != 0)
	{
		i = 0;
		while (*src && i < len)
			dst[i++] = *src++;
		while (i < len)
			dst[i++] = '\0';
	}
	return (dst);
}

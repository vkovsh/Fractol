/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 12:16:59 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/09 15:14:36 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*cpy;
	char	*buf;
	size_t	length;

	if (!(*needle))
		return ((char *)haystack);
	length = ft_strlen(needle);
	cpy = (char *)haystack;
	buf = (char *)(haystack + len);
	while ((cpy = ft_strchr(cpy, *needle)) && cpy <= buf)
	{
		if ((cpy + length <= buf) && !ft_strncmp(cpy, needle, length))
			return (cpy);
		cpy++;
	}
	return (NULL);
}

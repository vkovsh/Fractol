/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:58:55 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/08 14:58:12 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strchr(const char *s, int c)
{
	char	smb;

	smb = (char)c;
	while (*s != '\0')
	{
		if (*s == smb)
			return ((char *)s);
		s++;
	}
	if (*s == smb)
		return ((char *)s);
	return (NULL);
}

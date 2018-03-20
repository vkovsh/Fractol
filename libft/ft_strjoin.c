/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:22:09 by vkovsh            #+#    #+#             */
/*   Updated: 2017/12/08 12:55:48 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	char	*walkthrough;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((concat = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	concat[len] = '\0';
	walkthrough = concat;
	while (*s1)
		*walkthrough++ = *s1++;
	while (*s2)
		*walkthrough++ = *s2++;
	return (concat);
}

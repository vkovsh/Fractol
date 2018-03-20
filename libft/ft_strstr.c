/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 11:39:33 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/09 14:48:52 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	if (*needle == '\0')
		return ((char *)haystack);
	else
	{
		i = -1;
		while (haystack[++i])
		{
			j = 0;
			while (haystack[i + j] == needle[j])
			{
				if (!needle[j + 1])
					return ((char *)(haystack + i));
				j++;
			}
		}
	}
	return (NULL);
}

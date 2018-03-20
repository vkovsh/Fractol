/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:28:34 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/08 15:31:34 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*new;

	if (s && f)
	{
		len = ft_strlen(s);
		if ((new = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		new[len] = '\0';
		while (len-- != 0)
			new[len] = f(s[len]);
		return (new);
	}
	return (NULL);
}

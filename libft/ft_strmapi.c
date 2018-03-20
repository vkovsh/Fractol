/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:38:22 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/08 15:32:44 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*new;

	if (s && f)
	{
		len = (unsigned int)ft_strlen(s);
		if ((new = (char *)malloc(len + 1)) == NULL)
			return (NULL);
		new[len] = '\0';
		while (len-- != 0)
			new[len] = f(len, s[len]);
		return (new);
	}
	return (NULL);
}

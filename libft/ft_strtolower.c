/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:52:00 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/09 16:10:47 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtolower(char const *s)
{
	size_t	len;
	char	*res;

	len = ft_strlen(s);
	res = ft_strnew(len + 1);
	while (len--)
		res[len] = ft_tolower(s[len]);
	return (res);
}

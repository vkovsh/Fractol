/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:14:20 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/09 16:24:22 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtoupper(char const *s)
{
	size_t	len;
	char	*res;

	len = ft_strlen(s);
	res = ft_strnew(len + 1);
	while (len--)
		res[len] = ft_toupper(s[len]);
	return (res);
}

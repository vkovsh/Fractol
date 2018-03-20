/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:54:00 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/08 13:14:34 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*new;

	if ((new = (char *)malloc(size + 1)) == NULL)
		return (NULL);
	ft_bzero(new, size + 1);
	return (new);
}

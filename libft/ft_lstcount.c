/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:32:19 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/10 17:56:25 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstcount(t_list **lst)
{
	size_t	count;
	t_list	*buf;

	if (!lst)
		return (0);
	count = 0;
	buf = *lst;
	while (buf)
	{
		count++;
		buf = buf->next;
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:36:58 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/09 14:29:43 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*data;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		data = ft_memalloc(content_size);
		ft_memcpy(data, content, content_size);
		if ((new->content = (void *)malloc(content_size)) == NULL)
		{
			free(new);
			return (NULL);
		}
		new->content = data;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}

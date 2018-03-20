/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:37:07 by vkovsh            #+#    #+#             */
/*   Updated: 2018/01/03 12:26:28 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static t_list		*get_correct_file(t_list **file, int fd)
{
	t_list			*tmp;

	tmp = *file;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = (t_list *)malloc(sizeof(t_list));
	tmp->content = ft_strnew(0);
	tmp->content_size = fd;
	tmp->next = *file;
	*file = tmp;
	return (tmp);
}

static void			ft_cut(t_list *entry, int split)
{
	char			*new_str;
	int				len;

	len = (int)ft_strlen(entry->content);
	new_str = ft_strnew(len - split);
	ft_strcpy(new_str, entry->content + split);
	free(entry->content);
	entry->content = new_str;
}

static int			ft_copyuntil(char **line, t_list *entry, char c)
{
	int				i;
	int				count;

	i = -1;
	count = 0;
	while (((char *)(entry->content))[++i])
		if (((char *)(entry->content))[i] == c)
			break ;
	if (!(*line = ft_strnew(i)))
		return (-1);
	ft_strncpy(*line, entry->content, i);
	if (!(*line))
		return (-1);
	if (i < (int)ft_strlen(entry->content))
		ft_cut(entry, i + 1);
	else
		ft_strclr(entry->content);
	return (0);
}

static int			ft_strjoin_clean(t_list *entry, char *add)
{
	char			*del;

	del = entry->content;
	if (!(entry->content = ft_strjoin(del, add)))
		return (0);
	ft_strdel(&del);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*file;
	int				ret;
	t_list			*text;

	if ((fd < 0 || !line || read(fd, buf, 0) < 0))
		return (-1);
	text = get_correct_file(&file, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!ft_strjoin_clean(text, buf))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(text->content))
		return (0);
	if (ft_copyuntil(line, text, '\n') == -1)
		return (-1);
	return (1);
}

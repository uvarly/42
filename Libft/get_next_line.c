/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:29:57 by uvarly            #+#    #+#             */
/*   Updated: 2019/01/05 11:27:19 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		gnl_shutdown(t_list **list)
{
	t_list	*temp;

	while (*list)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp->content);
		free(temp);
	}
	return (-1);
}

static t_list	*get_node(int fd, t_list **list)
{
	t_list	*temp;

	if (!*list)
	{
		if (!(*list = ft_lstnew(NULL, 0)))
			return (NULL);
		(*list)->content_size = fd;
		return (*list);
	}
	temp = *list;
	while (temp->content_size != fd && temp->next)
		temp = temp->next;
	if (temp->content_size == fd)
		return (temp);
	if (!(temp->next = ft_lstnew(NULL, 0)))
		return (NULL);
	temp->content_size = fd;
	return (temp);
}

static int		read_to_node(t_list *list)
{
	char	*temp;
	char	buf[BUFF_SIZE + 1];
	ssize_t	ret;

	if (list->content && ft_strchr(list->content, '\n'))
		return (1);
	while ((ret = read(list->content_size, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		temp = list->content;
		if (!(list->content = list->content ?
				ft_strjoin(list->content, buf) : ft_strdup(buf)))
			return (-1);
		temp ? ft_strdel(&temp) : NULL;
		if (ft_strchr(list->content, '\n'))
			return (1);
	}
	return (list->content ? 1 : ret);
}

static int		write_to_line(t_list *list, char **line)
{
	char	*temp;
	ssize_t	ret;

	ret = read_to_node(list);
	if (ret < 1)
		return (ret);
	if (!*(char *)(list->content))
	{
		ft_strdel((char **)&(list->content));
		return (0);
	}
	temp = ft_strchr(list->content, '\n');
	if (!(*line = (temp) ? ft_strndup(list->content,
			(temp - (char *)(list->content))) : ft_strdup(list->content)))
		return (-1);
	if (!temp)
		ft_strdel((char **)&(list->content));
	else
	{
		temp = list->content;
		if (!(list->content = ft_strdup(ft_strchr(list->content, '\n') + 1)))
			return (-1);
		ft_strdel(&temp);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*temp;
	ssize_t			ret;

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!(temp = get_node(fd, &list)))
		return (gnl_shutdown(&list));
	ret = write_to_line(temp, line);
	if (ret == -1)
		return (gnl_shutdown(&list));
	return (ret);
}

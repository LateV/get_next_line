/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:41:11 by vibondar          #+#    #+#             */
/*   Updated: 2017/12/04 19:41:12 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_putline(char **line, char *buf, char c)
{
	int		start;
	int		j;
	int		i;
	char	*line_str;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == c)
			break ;
		i++;
	}
	start = i;
	j = 0;
	line_str = ft_strnew(i);
	while (buf[j] && j < i)
	{
		line_str[j] = buf[j];
		j++;
	}
	line_str[j] = '\0';
	*line = line_str;
	return (start);
}

t_list		*curr_file(t_list **afiles, int fd)
{
	t_list *che;

	che = *afiles;
	while (che)
	{
		if ((int)che->content_size == fd)
			return (che);
		che = che->next;
	}
	che = ft_lstnew("", fd);
	ft_lstadd(afiles, che);
	return (che);
}

int			get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				i;
	int				kol;
	t_list			*curline;
	static t_list	*afiles;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	curline = curr_file(&afiles, fd);
	while ((kol = read(fd, buf, BUFF_SIZE)))
	{
		buf[kol] = '\0';
		(curline->content = ft_strjoin(curline->content, buf));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (kol < BUFF_SIZE && !ft_strlen(curline->content))
		return (0);
	i = ft_putline(line, curline->content, '\n');
	if (i < (int)ft_strlen(curline->content))
		curline->content = curline->content + (i + 1);
	else
		ft_strclr(curline->content);
	return (1);
}

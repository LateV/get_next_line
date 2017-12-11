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

void					ft_put(t_getline *num, int i)
{
	char				*tmp;
	int					j;

	j = 0;
	while (num->content[num->pos] != '\0')
		num->pos++;
	tmp = ft_strnew(num->pos - i + 1);
	while (num->content[i] != '\0')
	{
		tmp[j] = num->content[i + 1];
		j++;
		i++;
	}
	tmp[j] = '\0';
	free(num->content);
	num->content = ft_strnew(num->pos - j + 1);
	ft_strcpy(num->content, tmp);
	free(tmp);
	num->pos = 0;
}

int						ft_putline(t_getline *num, char **line, int i)
{
	char				*line_str;

	while (num->content[i] != '\0' && num->content[i] != '\n')
	{
		num->pos++;
		i++;
	}
	line_str = ft_strnew(num->pos);
	ft_strncpy(line_str, num->content, num->pos);
	*line = line_str;
	ft_put(num, i);
	return (1);
}

t_getline				*curr_file(t_getline **afiles, int fd)
{
	t_getline			*che;

	che = *afiles;
	while (che)
	{
		if (che->content_size == fd)
			return (che);
		che = che->next;
	}
	che = (t_getline*)malloc(sizeof(t_getline) * 1);
	che->content = ft_strdup("");
	che->content_size = fd;
	che->next = *afiles;
	che->pos = 0;
	*afiles = che;
	return (che);
}

char					*ft_strjoinmy(char *s1, char *s2)
{
	char				*str;
	int					len;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	free(s1);
	return (str);
}

int						get_next_line(const int fd, char **line)
{
	char				buf[BUFF_SIZE + 1];
	char				*tmp;
	int					kol;
	t_getline			*curline;
	static t_getline	*afiles;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	curline = curr_file(&afiles, fd);
	if (ft_strchr(curline->content, '\n') == NULL)
	{
		while ((kol = read(fd, buf, BUFF_SIZE)))
		{
			buf[kol] = '\0';
			tmp = ft_strjoinmy(curline->content, buf);
			curline->content = tmp;
			if (ft_strchr(buf, '\n'))
				break ;
		}
	}
	if (ft_strlen(curline->content) == 0)
		return (0);
	return (ft_putline(curline, line, 0));
}

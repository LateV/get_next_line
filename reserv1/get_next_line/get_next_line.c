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

int			ft_putline(t_getline *num, char **line, char c, int i)
{
	int		j;
	char	*line_str;

	j = num->pos;
	i = i + num->pos;
	while (num->content[num->pos] != '\0')
	{
		if (num->content[num->pos] == c)
			break ;
		num->pos++;
		i++;
	}
	num->pos++;
	line_str = ft_strnew(i);
	//printf("j = %d\n", j);
	//printf("i = %d\n", i);
	while (j < i)
	{
		line_str[j] = num->content[j];
		j++;
	}
	*line = line_str;
	if(num->content[j] == '\0')
	{
		free(num->content);
		return (0);
	}
	free(num->content);
	return (1);
}

t_getline		*curr_file(t_getline **afiles, int fd)
{
	t_getline *che;

	che = *afiles;
	while (che)
	{
		if (che->content_size == fd)
		{
			che->content = ft_strdup("");
			return (che);
		}
		che = che->next;
	}
	che =(t_getline*)malloc(sizeof(t_getline) * 1);
	che->content = ft_strdup("");
	che->content_size = fd;
	che->next = *afiles;
	che->pos = 0;
	*afiles = che;
	return (che);
}

char		*ft_strjoinmy(char *s1, char *s2)
{
	char	*str;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	free(s1);
	return(str);
}

int			get_next_line(const int fd, char **line)
{
	char				buf[BUFF_SIZE + 1];
	char				*tmp;
	int					kol;
	t_getline			*curline;
	static t_getline	*afiles;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	curline = curr_file(&afiles, fd);
	while ((kol = read(fd, buf, BUFF_SIZE)))
	{
		buf[kol] = '\0';
		tmp = ft_strjoinmy(curline->content, buf);
		curline->content = tmp;
		if (kol < BUFF_SIZE)
			break ;
	}
	return(ft_putline(curline, line, '\n', 0));
}

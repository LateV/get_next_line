/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:24:59 by vibondar          #+#    #+#             */
/*   Updated: 2017/11/20 17:25:00 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(const int fd, char **line)
{
	char	str[5] = "";
	char	str1[5] = "";
	int		ch;
	int		i;
	t_file 	*fdr;
	/*
	printf("!line = %d\n", !line);
	printf("fd < 0 = %d\n", fd < 0);
	printf("ch < 0 = %d\n", ch = read(fd, str, 10));
	*/
	i = 0;

	if (!line || fd < 0 || (ch = read(fd, NULL, 0)) < 0)
		return (-1);
	fdr = (t_file*)malloc(sizeof(t_file) * 8);
	fdr[i].fd = &fd;
	/*
	if (fdr[i].fd == fd)
		i++;
	fdr[i].fd = fd;
	*/
	printf("fd[0] = %d\n", fdr[0].fd);
	/*
	printf("fd[1] = %d\n", fdr[1].fd);
	*/
	read(fdr[0].fd , str , 5);
	//read(fdr[1].fd, str1 , 5);
	printf("%s\n", str);
	//printf("%s\n", str1);

	return (0);
}



int main(int argc, char **argv)
{
	int		fd;
	int		fd1;
	int		fd2;
	int		i;
	char	**file;

	file = (char**)malloc(sizeof(char*) * 8);
	argc = 1;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd,file);
	close(fd);
	fd1 = open(argv[2], O_RDONLY);
	get_next_line(fd1,file);
	close(fd1);
	fd2 = open(argv[3], O_RDONLY);
	get_next_line(fd2,file);
	close(fd2);
	return (0);
}
int ft_putline(char **line, char *buf, '\n')
{
	char *linep;
	int lenth;

}






int						get_next_line(const int fd, char **line)
{
	char				buf[BUFF_SIZE + 1];
	static t_list		*file;
	int					lenth;
	int					ret;
	t_list				*curr;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	curr = get_correct_file(&file, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		(curr->content = ft_strjoin(curr->content, buf));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(curr->content))
		return (0);
	i = ft_putline(line, curr->content, '\n');
	if(i < (int)ft_strlen(curr->content))
		curr->content += (i + 1);
	else
		ft_strclr(curr->content);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	if (argc == 2)
		close(fd);
}

// gcc get_next_line.c libft/ft_strlen.c libft/ft_strnew.c libft/ft_lstnew.c libft/ft_lstadd.c libft/ft_strjoin.c libft/ft_strchr.c libft/ft_strclr.c libft/ft_memalloc.c libft/ft_memcpy.c libft/ft_strcpy.c libft/ft_strcat.c libft/ft_bzero.c libft/ft_putendl.c libft/ft_putchar.c -o get

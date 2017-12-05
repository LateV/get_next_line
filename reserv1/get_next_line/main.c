#include "get_next_line.h"

int main(int argc, char **argv)
{
	int		fd;
	int		fd1;
	int		fd2;
	int		i;

	char	*file;
	char	*file1;
	char	*file3;
	char	*file4;
	i = 0;
	argc = 1;
	fd	= open(argv[1], O_RDONLY);
	fd1	= open(argv[2], O_RDONLY);
	fd2	= open(argv[3], O_RDONLY);
	/*
	get_next_line(fd, &file);
	printf("file = %s\n", file);
	*/
	get_next_line(fd, &file);
	printf("file = %s\n", file);
	get_next_line(fd, &file1);
	printf("file 1 = %s\n", file1);
	/*
	while(get_next_line(fd, &file))
	{
		printf("%d\n",i );
		printf("%s\n", file);
		free(file);
	}
*/

/*

	get_next_line(fd, &file);					//text5
	printf("file1 = %s\n",file);

	get_next_line(fd, &file );
	printf("file1 = %s\n",file);

	get_next_line(fd, &file );
	printf("file1 = %s\n",file);
*/

/*
	file[i] = (char*)malloc(sizeof(char) * 50);
	while(get_next_line(fd, &file[i]))
	{
		
		printf("%s\n", file[i] );
		i++;
		file[i] = (char*)malloc(sizeof(char) * 50);
	}
	while(i < 10)
	{
		get_next_line(fd1, &file[i]);
		printf("%s\n", file[i]);
		i++;
		file[i] = (char*)malloc(sizeof(char) * 50);
	}
	while(get_next_line(fd2, &file[i]))
	{
		printf("%s\n", file[i] );
		i++;
		file[i] = (char*)malloc(sizeof(char) * 50);
	}
	while(get_next_line(fd1, &file[i]))
	{
		printf("%s\n", file[i] );
		i++;
		file[i] = (char*)malloc(sizeof(char) * 50);
	}
	*/
	close(fd);
	close(fd1);
	close(fd2);
	/*
	while (1)
	{

	}
	*/
	return (0);
}



/*
int (int argc, char **argv)
{
	int		fd;
	int		fd1;
	int		fd2;
	int		i;

	char	**file;
	i = 0;
	file = (char**)malloc(sizeof(char*) * 200);
	argc = 1;
	fd	= open(argv[1], O_RDONLY);
	fd1	= open(argv[2], O_RDONLY);
	fd2	= open(argv[3], O_RDONLY);

	file[i] = (char*)malloc(sizeof(char) * 50);
	while(get_next_line(fd, &file[i]))
	{
		
		printf("%s\n", file[i - 1] );
		i++;
		file[i] = (char*)malloc(sizeof(char) * 50);
	}
	while(i < 10)
	{
		get_next_line(fd1, &file[i]);
		printf("%s\n", file[i]);
		i++;
		file[i] = (char*)malloc(sizeof(char) * 50);
	}
	while(get_next_line(fd2, &file[i]))
	{
		printf("%s\n", file[i] );
		i++;
		file[i] = (char*)malloc(sizeof(char) * 50);
	}
	while(get_next_line(fd1, &file[i]))
	{
		printf("%s\n", file[i] );
		i++;
		file[i] = (char*)malloc(sizeof(char) * 50);
	}
	close(fd);
	close(fd1);
	close(fd2);
	return (0);
}
*/

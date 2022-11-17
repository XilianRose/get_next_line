/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/11 12:19:29 by mstegema      #+#    #+#                 */
/*   Updated: 2022/11/17 15:47:46 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*ft_find_line(char *buffer)
{
	char	*end;
	char	*line;
	size_t	i;

	i = 0;
	end = ft_strchr(buffer, '\n');
	if (end == NULL)
		end = ft_strchr(buffer, '\0');
	while (buffer != end)
	{
		buffer++;
		i++;
	}
	line = ft_calloc(i, sizeof(char));
	if (!line)
		return (NULL);
	ft_memcpy(line, buffer, i);
	return (line);
}

char	*ft_read_check(char *buffer, char *read_char, int bytes)
{
	char		*temp;

	if (bytes < 0)
	{
		if (buffer)
			free(buffer);
		return (NULL);
	}
	if (bytes > 0)
	{
		temp = buffer;
		if (buffer)
			free(buffer);
		buffer = ft_strjoin_gnl(temp, read_char);
	}
	return (buffer);
}

/*	this is the function that actually reads the file.
		the variable "bytes" is set to buffer_size to start off with so

	reads unless buffer contains \n and till EOF */
char	*ft_read_file(int fd, char *buffer)
{
	int			bytes;
	char		*read_char;

	bytes = BUFFER_SIZE;
	read_char = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!read_char)
		return (NULL);
	while (ft_strchr(read_char, '\n') == NULL && bytes == BUFFER_SIZE)
	{
		bytes = read(fd, read_char, BUFFER_SIZE);
		buffer = ft_read_check(buffer, read_char, bytes);
	}
	return (buffer);
}

//	this is the general get_next_line function.
//		it checks for errors such as:
//			- read errors
//			- fd errors
//			- buffer size being too small to use
//		it then calls on the function used to read the file and safes the
//		outcome to the variable "line".

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	line = NULL;
	if (read(fd, 0, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer == NULL)
		buffer = ft_read_file(fd, buffer);
	if (buffer)
		line = ft_find_line(buffer);
	return (line);
}

//	in this main i take a textfile as argument and open it.
//		it starts of with eror handling such as:
//			- no argument
//			- error with opening file
//		after this it calls on the get_next_line function with the given fd
//		in a loop, printing it each time, untill error or EOF.

int	main(int argc, char **argv)
{
	int		fd;
	char	*line = "start";

	if (argc != 2)
	{
		printf("\nplease enter one filename as argument\n\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("\nencountered problem opening file\nfd = %i\n\n", fd);
		return (fd);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	close(fd);
	return (0);
}

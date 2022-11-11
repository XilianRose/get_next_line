/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/11 12:19:29 by mstegema      #+#    #+#                 */
/*   Updated: 2022/11/11 15:32:43 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// reads unless buffer contains \n and till EOF
char	*ft_read_file(int fd, char *buf)
{
	size_t	bytes;
	char	*temp;

	bytes = BUFFER_SIZE;
	while (ft_strchr(temp, '\n') == NULL && bytes == BUFFER_SIZE)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		temp[bytes] = '\0';
		if (bytes > 0)
			buf = ft_strjoin(buf, temp);
		else
			break ;
	}
	return (free(temp), buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	line = NULL;
	if (read(fd, 0, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0)
		return (line);
	line = ft_read_file(fd, buf);
	return (line);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line = "test";
// open 1 file at a time to test
	if (argc != 2)
	{
		printf("\nplease enter one filename as argument\n\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	printf("\nfd = %i\n\n", fd);
// calls gnl and prints return untill error or EOF
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	close(fd);
	return (0);
}

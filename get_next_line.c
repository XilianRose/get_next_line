/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/11 12:19:29 by mstegema      #+#    #+#                 */
/*   Updated: 2022/09/23 15:37:29 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*read_file(int fd, char *buf)
{
	size_t	bytes;
	char	*temp;

	bytes = BUFFER_SIZE;
// for first call
	if (!buf)
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (bytes == BUFFER_SIZE)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (ft_strchr(buf, '\n') == NULL && bytes == BUFFER_SIZE)
		{
			temp = buf;
			bytes = read(fd, buf, BUFFER_SIZE);
			buf = ft_strjoin(temp, buf);
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

// safety
	if (read(fd, 0, 0) < 0 || !fd || BUFFER_SIZE <= 0)
		return (NULL);
// read function
	line = read_file(fd, buf);
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;
// // open 1 file at a time to test
// 	if (argc != 2)
// 		return (0);
// 	fd = open(argv[1], O_RDONLY);
// // calls gnl and prints return untill error or EOF
// 	while (line != NULL)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 	}
// 	close(fd);
// 	return (0);
// }

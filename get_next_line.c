/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/11 12:19:29 by mstegema      #+#    #+#                 */
/*   Updated: 2022/09/25 13:26:58 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*ft_read_file(int fd, char *buf)
{
	size_t	bytes;
	char	*temp;

	bytes = BUFFER_SIZE;
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
// reads unless buffer contains \n and till EOF
	while (ft_strchr(temp, '\n') == NULL && bytes == BUFFER_SIZE)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		temp[bytes] = '\0';
		if (bytes > 0)
			buf = ft_strjoin(buf, temp);
		else
			break;
	}
	return (free(temp), buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

// safety
	if (read(fd, 0, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
// read function
	buf = ft_read_file(fd, buf);
// get line function
	return (line);
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

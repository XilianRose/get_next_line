/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/11 12:19:29 by mstegema      #+#    #+#                 */
/*   Updated: 2022/08/26 15:54:06 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*str;

// safety
	if (read(fd, 0, 0) < 0 || !fd || BUFFER_SIZE <= 0)
		return (NULL);
// malloc the buffer
	buf = ft_gnl_calloc(BUFFER_SIZE + 1, sizeof(char));

	while (read(fd, buf, 1) > 0)
	{

	}
	if (!str)
		return (free(str), NULL);
	return (str);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;

// open 1 file at a time to test
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
// calls gnl and prints return untill error or EOF
	while (str != NULL)
	{
		str = get_next_line(fd);
		printf("%s", str);
	}
	close(fd);
	return (0);
}

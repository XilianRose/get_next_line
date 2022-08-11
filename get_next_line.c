/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/11 12:19:29 by mstegema      #+#    #+#                 */
/*   Updated: 2022/08/11 15:49:48 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char			buf[1];
	size_t			line_len;
	static size_t	current = 0;
	char			*str;

	line_len = 0;
	while (*buf != '\n')
	{
		printf("\nbuff contains: %s\nline_len = %zu", buf, line_len);
		printf("\ncurrent = %zu\n\n", current);
		read(fd, buf, 1);
		line_len ++;
		current ++;
	}
	str = calloc(line_len, sizeof(char));
	read(fd, str, line_len);
	return (str);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc > 1)
		return (0);
	fd = open(argv[1], O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}

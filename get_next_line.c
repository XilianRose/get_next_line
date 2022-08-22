/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/11 12:19:29 by mstegema      #+#    #+#                 */
/*   Updated: 2022/08/22 15:34:38 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char			*buf;
	size_t			line_len;
	static size_t	current = 0;
	char			*str;

	line_len = 0;
	while (buf != '\n')
	{
		// printf("\nbuff contains: %c\nline_len = %zu", buf, line_len);
		// printf("\ncurrent = %zu\n\n", current);
		read(fd, buf, 1);
		while (buf != '\n')
		{
			line_len ++;
			current ++;
		}
	}
	str = ft_strjoin(str, buf);
	if (!str)
		return (free(str), NULL);
	return (str);
}

// read 1 line at a time
// loop until \n
// calloc concat

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}

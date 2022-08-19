/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/11 12:19:29 by mstegema      #+#    #+#                 */
/*   Updated: 2022/08/19 15:48:15 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	void	*ret;

	ret = b;
	while (len > 0)
	{
		*(unsigned char *)b = (unsigned char)c;
		len--;
		b++;
	}
	return (ret);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
	return ;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = malloc(count * size);
	if (res)
		ft_bzero(res, count * size);
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len_s1;
	size_t	len_s2;
	size_t	count;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	count = len_s1 + len_s2 + 1;
	res = ft_calloc(count, sizeof(char));
	if (res)
	{
		ft_memcpy(res, s1, len_s1);
		ft_memcpy(res + len_s1, s2, len_s2);
		return (res);
	}
	return (NULL);
}

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
	str = ft_strconcat(str, buf);
	if (!str)
		return (NULL);

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

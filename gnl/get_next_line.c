/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:33:21 by vjose             #+#    #+#             */
/*   Updated: 2021/10/19 13:33:21 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_check_remainder(char *remainder)
{
	char	*line;
	size_t	i;

	i = 0;
	while (remainder[i] != '\0')
	{
		if (remainder[i] == '\n')
		{
			line = ft_substr(remainder, 0, i + 1);
			ft_memcpy(remainder, remainder + i + 1, BUFFER_SIZE - i - 1);
			return (line);
		}
		i++;
	}
	return (NULL);
}

static char	*ft_concatenation(char *remainder, char *line, char *buf)
{
	char	*buffer;

	if (remainder[0] != '\0')
	{
		line = ft_strjoin(remainder, buf);
		remainder[0] = '\0';
	}
	else
	{
		if (line == NULL)
			line = ft_strdup(buf);
		else
		{		
			buffer = ft_strdup(line);
			free(line);
			line = ft_strjoin(buffer, buf);
			free(buffer);
		}
	}
	free(buf);
	return (line);
}

static char	*ft_return_line(char *remainder, char *line)
{
	int		i;
	char	*buf;

	if (line == NULL)
		return (NULL);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			buf = ft_substr(line, 0, i + 1);
			ft_memcpy(remainder, line + i + 1, ft_strlen(line) - i);
			free(line);
			return (buf);
		}
		i++;
	}
	return (NULL);
}

static char	*ft_end_of_file(char *remainder, char *line, char *buf)
{
	free(buf);
	if (line != NULL)
		return (line);
	if (remainder[0] != '\0')
	{
		line = ft_strdup(remainder);
		remainder[0] = '\0';
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	remainder[BUFFER_SIZE + 1];
	int			r;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_check_remainder(remainder);
	if (line != NULL)
		return (line);
	while (1)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return (NULL);
		r = read(fd, buf, BUFFER_SIZE);
		if (r >= 0)
			buf[r] = '\0';
		if (r <= 0)
			return (ft_end_of_file(remainder, line, buf));
		line = ft_concatenation(remainder, line, buf);
		buf = ft_return_line(remainder, line);
		if (buf != NULL)
			return (buf);
	}
}

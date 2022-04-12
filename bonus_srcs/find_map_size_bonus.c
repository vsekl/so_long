/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map_size_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:38:12 by vjose             #+#    #+#             */
/*   Updated: 2021/12/21 17:38:17 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	count_map_length(char *argv)
{
	int		r;
	char	buf[BUFFER_SIZE + 1];
	char	*ptr;
	int		counter;
	int		fd;

	counter = 0;
	fd = open_file(argv);
	r = 1;
	while (r > 0)
	{
		ptr = buf;
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			error_read(fd);
		buf[r] = '\0';
		while (*ptr != '\0')
		{
			if (*(ptr++) == '\n')
				return (++counter);
			counter++;
		}
	}
	close(fd);
	return (++counter);
}

static int	count_map_height(char *argv)
{
	int		r;
	char	buf[BUFFER_SIZE + 1];
	char	*ptr;
	int		counter;
	int		fd;

	counter = 0;
	fd = open_file(argv);
	r = 1;
	while (r > 0)
	{
		ptr = buf;
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			error_read(fd);
		buf[r] = '\0';
		while (*ptr != '\0')
		{
			if (*(ptr++) == '\n')
				counter++;
		}
	}
	close(fd);
	return (++counter);
}

void	find_map_size(char *argv, t_coordinate *map_size)
{
	map_size->x = count_map_length(argv);
	map_size->y = count_map_height(argv);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:17:13 by vjose             #+#    #+#             */
/*   Updated: 2021/11/11 18:17:13 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	open_file(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		error_invalid_file();
	}
	return (fd);
}

void	fill_map(char *argv, t_game *game, t_coordinate *map_size)
{
	int	y;
	int	fd;

	y = 0;
	fd = open_file(argv);
	while (y < map_size->y)
	{
		game->map[y] = get_next_line(fd);
		if (game->map[y] == NULL)
			error_allocation();
		y++;
	}
	close(fd);
}

void	map_allocation(char *argv, t_game *game, t_coordinate *map_size)
{
	find_map_size(argv, map_size);
	if (map_size->x == 1 && map_size->y == 1)
		error_empty_map();
	game->map = malloc(sizeof(char *) * (map_size->y + 1));
	if (game->map == NULL)
		error_allocation();
	game->map[map_size->y] = NULL;
	fill_map(argv, game, map_size);
	check_map(game, map_size);
}

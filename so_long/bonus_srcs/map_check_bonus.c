/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:23:37 by vjose             #+#    #+#             */
/*   Updated: 2021/12/21 17:44:52 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "get_next_line.h"

static int	is_01cep_bonus(char c, t_cep *cep)
{
	if (!(c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == 'X'))
		return (0);
	if (c == 'C')
		cep->collectible++;
	else if (c == 'E')
		cep->exit++;
	else if (c == 'P')
		cep->player++;
	return (1);
}

static int	check_border_2(char **map, int y, int x, t_coordinate *map_size)
{
	if (map[y][x] == '\n')
	{
		if (map[y][x + 1] != '\0' || map[y][x - 1] != '1' \
									|| x + 1 != map_size->x)
			return (0);
		else
			return (2);
	}
	if ((y == 0 || x == 0 || y + 1 == map_size->y) && (map[y][x] != '1'))
		return (0);
	return (1);
}

static int	check_border(char **map, t_coordinate *map_size)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (check_border_2(map, y, x, map_size) == 0)
				return (0);
			else
			{
				x++;
				if (check_border_2(map, y, x, map_size) == 2)
					continue ;
			}
		}
		if (y + 1 == map_size->y && x + 1 != map_size->x)
			return (0);
		x = 0;
		y++;
	}
	return (1);
}

static int	check_cep_bonus(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y] != NULL)
	{
		while (game->map[y][x] != '\0' && game->map[y][x] != '\n')
		{
			if (is_01cep_bonus(game->map[y][x], &game->cep) == 0)
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	if (game->cep.collectible < 1 || game->cep.exit < 1 \
								|| game->cep.player != 1)
		return (0);
	return (1);
}

void	check_map(t_game *game, t_coordinate *map_size)
{
	if (check_border(game->map, map_size) == 0)
		error_wrong_border();
	init_variables(&game->cep);
	if (check_cep_bonus(game) == 0)
		error_wrong_cep();
}

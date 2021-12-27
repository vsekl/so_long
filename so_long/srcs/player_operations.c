/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:00:15 by vjose             #+#    #+#             */
/*   Updated: 2021/12/23 18:51:18 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coordinate	search_player_position(char **map)
{
	int				x;
	int				y;
	t_coordinate	player;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				player.x = x;
				player.y = y;
				return (player);
			}
			x++;
		}
		x = 0;
		y++;
	}
	player.x = -1;
	player.y = -1;
	return (player);
}

static int	do_step(t_game *game, int x, int y, t_coordinate pos)
{
	if (game->map[pos.y + y][pos.x + x] == 'E')
	{
		if (game->cep.collectible == 0)
		{
			printf("You won!\n");
			close_win(game);
		}
		printf("You can't leave an area now! Collect all coins!\n");
		return (0);
	}
	else if (game->map[pos.y + y][pos.x + x] == 'C')
		game->cep.collectible--;
	return (1);
}

void	move_player(t_game *game, int x, int y)
{
	static int		counter = 0;
	t_coordinate	pos;

	pos.x = game->player_position.x;
	pos.y = game->player_position.y;
	if (game->map[pos.y + y][pos.x + x] != '1')
	{
		if (do_step(game, x, y, pos) == 0)
			return ;
		game->map[pos.y + y][pos.x + x] = 'P';
		game->map[pos.y + y][pos.x + x] = '0';
		put_image_to_window(game, game->player.img, pos.x + x, pos.y + y);
		put_image_to_window(game, game->background.img, pos.x, pos.y);
		game->player_position.y = pos.y + y;
		game->player_position.x = pos.x + x;
		printf("Steps: %d\n", ++counter);
	}
	else
		printf("You can't move through the wall!\n");
}

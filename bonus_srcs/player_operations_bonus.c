/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_operations_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:02:41 by vjose             #+#    #+#             */
/*   Updated: 2021/12/23 18:51:09 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	do_step(t_game *game, int x, int y, t_coordinate pos)
{
	if (game->map[pos.y + y][pos.x + x] == 'X')
	{
		printf("Game over!\n");
		close_win(game);
	}
	if (game->map[pos.y + y][pos.x + x] == 'E')
	{
		if (game->cep.collectible == 0)
		{
			printf("You won!\n");
			close_win(game);
		}
		printf("You can't leave an area now! Collect all coins\n");
		return (0);
	}
	else if (game->map[pos.y + y][pos.x + x] == 'C')
		game->cep.collectible--;
	return (1);
}

void	next_step(t_game *game, int x, int y)
{
	static int		counter = 0;
	t_coordinate	pos;
	int				step;

	pos.x = game->player_position.x;
	pos.y = game->player_position.y;
	if (game->map[pos.y + y][pos.x + x] != '1')
	{
		step = do_step(game, x, y, pos);
		if (step == 0)
			return ;
		game->map[pos.y + y][pos.x + x] = 'P';
		game->map[pos.y][pos.x] = '0';
		put_image_to_window(game, game->background.img, pos.x, pos.y);
		move_player(game, pos, x, y);
		game->player_position.y = pos.y + y;
		game->player_position.x = pos.x + x;
		counter++;
		print_counter(game, counter);
		move_enemy(game);
	}
	else
		printf("You can't move through the wall!\n");
}

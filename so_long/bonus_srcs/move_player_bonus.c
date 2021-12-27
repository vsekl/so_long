/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:59:20 by vjose             #+#    #+#             */
/*   Updated: 2021/12/22 21:11:57 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_player_up(t_game *game, t_coordinate pos, int x, int y)
{
	if (game->player.last_operation == 6)
	{
		put_image_to_window(game, game->player.up_1.img, \
									pos.x + x, pos.y + y);
		game->player.last_operation = 5;
	}
	else
	{
		put_image_to_window(game, game->player.up_2.img, \
									pos.x + x, pos.y + y);
		game->player.last_operation = 6;
	}
}

static void	move_player_down(t_game *game, t_coordinate pos, int x, int y)
{
	if (game->player.last_operation == 8)
	{
		put_image_to_window(game, game->player.down_1.img, \
									pos.x + x, pos.y + y);
		game->player.last_operation = 7;
	}
	else
	{
		put_image_to_window(game, game->player.down_2.img, \
									pos.x + x, pos.y + y);
		game->player.last_operation = 8;
	}
}

static void	move_player_left(t_game *game, t_coordinate pos, int x, int y)
{
	if (game->player.last_operation == 2)
	{
		put_image_to_window(game, game->player.left_1.img, \
									pos.x + x, pos.y + y);
		game->player.last_operation = 1;
	}
	else
	{
		put_image_to_window(game, game->player.left_2.img, \
									pos.x + x, pos.y + y);
		game->player.last_operation = 2;
	}
}

static void	move_player_right(t_game *game, t_coordinate pos, int x, int y)
{
	if (game->player.last_operation == 4)
	{
		put_image_to_window(game, game->player.right_1.img, \
									pos.x + x, pos.y + y);
		game->player.last_operation = 3;
	}
	else
	{
		put_image_to_window(game, game->player.right_2.img, \
									pos.x + x, pos.y + y);
		game->player.last_operation = 4;
	}
}

void	move_player(t_game *game, t_coordinate pos, int x, int y)
{
	if (y == -1)
		move_player_up(game, pos, x, y);
	else if (y == 1)
		move_player_down(game, pos, x, y);
	else if (x == -1)
		move_player_left(game, pos, x, y);
	else if (x == 1)
		move_player_right(game, pos, x, y);
}

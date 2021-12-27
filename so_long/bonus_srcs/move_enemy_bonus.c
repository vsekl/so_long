/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:46:18 by vjose             #+#    #+#             */
/*   Updated: 2021/12/24 16:08:34 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	move_enemy_up(t_game *game)
{
	if (game->enemy_coords->direction == 'w')
	{
		if (game->map[game->enemy_coords->y - 1][game->enemy_coords->x] == 'P')
		{
			printf("Game over!\n");
			close_win(game);
		}
		if (game->map[game->enemy_coords->y - 1][game->enemy_coords->x] == '0')
		{
			game->map[game->enemy_coords->y - 1][game->enemy_coords->x] = 'X';
			game->map[game->enemy_coords->y][game->enemy_coords->x] = '0';
			put_image_to_window(game, game->enemy.up.img, \
							game->enemy_coords->x, game->enemy_coords->y - 1);
			put_image_to_window(game, game->background.img, \
							game->enemy_coords->x, game->enemy_coords->y);
			game->enemy_coords->y--;
		}
		else
		{
			game->enemy_coords->direction = 's';
			return (0);
		}	
	}
	return (1);
}

static int	move_enemy_down(t_game *game)
{
	if (game->enemy_coords->direction == 's')
	{
		if (game->map[game->enemy_coords->y + 1][game->enemy_coords->x] == 'P')
		{
			printf("Game over!\n");
			close_win(game);
		}
		if (game->map[game->enemy_coords->y + 1][game->enemy_coords->x] == '0')
		{
			game->map[game->enemy_coords->y + 1][game->enemy_coords->x] = 'X';
			game->map[game->enemy_coords->y][game->enemy_coords->x] = '0';
			put_image_to_window(game, game->enemy.down.img, \
						game->enemy_coords->x, game->enemy_coords->y + 1);
			put_image_to_window(game, game->background.img, \
						game->enemy_coords->x, game->enemy_coords->y);
			game->enemy_coords->y++;
		}
		else
		{
			game->enemy_coords->direction = 'w';
			return (0);
		}
	}
	return (1);
}

static int	enemy_move_check(t_game *game)
{
	if (game->map[game->enemy_coords->y - 1][game->enemy_coords->x] == '0' || \
		(game->map[game->enemy_coords->y + 1][game->enemy_coords->x] == '0'))
		return (1);
	if (game->map[game->enemy_coords->y - 1][game->enemy_coords->x] == 'P' || \
		(game->map[game->enemy_coords->y + 1][game->enemy_coords->x] == 'P'))
	{
		printf("Game over!\n");
		close_win(game);
	}
	return (0);
}

void	move_enemy(t_game *game)
{
	t_list	*start;

	start = game->enemy_coords;
	while (game->enemy_coords != NULL)
	{
		if (enemy_move_check(game) == 0)
		{
			game->enemy_coords = game->enemy_coords->next;
			continue ;
		}
		if (move_enemy_up(game) == 0)
			continue ;
		if (move_enemy_down(game) == 0)
			continue ;
		game->enemy_coords = game->enemy_coords->next;
	}
	game->enemy_coords = start;
}

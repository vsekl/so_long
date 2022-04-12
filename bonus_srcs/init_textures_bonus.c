/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 21:20:43 by vjose             #+#    #+#             */
/*   Updated: 2021/12/23 18:17:35 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_nums_textures(t_game *game)
{
	game->steps.num_0 = init_textures(game->mlx, "textures/0.xpm");
	game->steps.num_1 = init_textures(game->mlx, "textures/1.xpm");
	game->steps.num_2 = init_textures(game->mlx, "textures/2.xpm");
	game->steps.num_3 = init_textures(game->mlx, "textures/3.xpm");
	game->steps.num_4 = init_textures(game->mlx, "textures/4.xpm");
	game->steps.num_5 = init_textures(game->mlx, "textures/5.xpm");
	game->steps.num_6 = init_textures(game->mlx, "textures/6.xpm");
	game->steps.num_7 = init_textures(game->mlx, "textures/7.xpm");
	game->steps.num_8 = init_textures(game->mlx, "textures/8.xpm");
	game->steps.num_9 = init_textures(game->mlx, "textures/9.xpm");
}

void	init_player_textures(t_game *game)
{
	game->player.right_1 = init_textures(game->mlx, \
						"textures/player_right_1.xpm");
	game->player.right_2 = init_textures(game->mlx, \
						"textures/player_right_2.xpm");
	game->player.left_1 = init_textures(game->mlx, \
						"textures/player_left_1.xpm");
	game->player.left_2 = init_textures(game->mlx, \
						"textures/player_left_2.xpm");
	game->player.up_1 = init_textures(game->mlx, \
						"textures/player_up_1.xpm");
	game->player.up_2 = init_textures(game->mlx, \
						"textures/player_up_2.xpm");
	game->player.down_1 = init_textures(game->mlx, \
						"textures/player_down_1.xpm");
	game->player.down_2 = init_textures(game->mlx, \
						"textures/player_down_2.xpm");
}

void	init_enemy_textures(t_game *game)
{
	game->enemy.up = init_textures(game->mlx, "textures/enemy_up.xpm");
	game->enemy.down = init_textures(game->mlx, "textures/enemy_down.xpm");
}

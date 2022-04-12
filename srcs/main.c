/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:46:58 by vjose             #+#    #+#             */
/*   Updated: 2021/11/02 19:46:58 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_win(game);
	else if (keycode == KEY_W)
		move_player(game, 0, -1);
	else if (keycode == KEY_A)
		move_player(game, -1, 0);
	else if (keycode == KEY_S)
		move_player(game, 0, 1);
	else if (keycode == KEY_D)
		move_player(game, 1, 0);
	return (0);
}

void	render_map_2(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1' )
		put_image_to_window(game, game->wall.img, x, y);
	else if (game->map[y][x] == '0' )
		put_image_to_window(game, game->background.img, x, y);
	else if (game->map[y][x] == 'P' )
		put_image_to_window(game, game->player.img, x, y);
	else if (game->map[y][x] == 'C' )
		put_image_to_window(game, game->collectible.img, x, y);
	else if (game->map[y][x] == 'E' )
		put_image_to_window(game, game->map_exit.img, x, y);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y] != NULL)
	{
		while (game->map[y][x] != '\0')
		{
			render_map_2(game, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_coordinate	map_size;
	t_game			game;

	if (argc != 2)
		error_wrong_params();
	map_allocation(argv[1], &game, &map_size);
	init_game(&game, map_size);
	render_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 1L << 17, close_win, &game);
	mlx_loop(game.mlx);
	return (0);
}

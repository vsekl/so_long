/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:43:49 by vjose             #+#    #+#             */
/*   Updated: 2021/12/23 20:59:35 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	init_textures(void *mlx, char *filename)
{
	t_data	data;
	int		width;
	int		height;

	width = 0;
	height = 0;
	data.img = mlx_xpm_file_to_image(mlx, filename, &width, &height);
	if (data.img == NULL)
		error_not_xpm();
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
								&data.line_length, &data.endian);
	return (data);
}

void	init_variables(t_cep *cep)
{
	cep->collectible = 0;
	cep->exit = 0;
	cep->player = 0;
}

void	init_game(t_game *game, t_coordinate map_size)
{
	game->img_size = 75;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->img_size * (map_size.x - 1), \
							game->img_size * map_size.y, "so_long");
	game->background = init_textures(game->mlx, "textures/background.xpm");
	game->wall = init_textures(game->mlx, "textures/wall.xpm");
	game->player = init_textures(game->mlx, "textures/player_down_1.xpm");
	game->collectible = init_textures(game->mlx, "textures/collectible.xpm");
	game->map_exit = init_textures(game->mlx, "textures/exit.xpm");
	game->player_position = search_player_position(game->map);
}

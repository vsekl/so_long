/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:02:31 by vjose             #+#    #+#             */
/*   Updated: 2021/12/23 18:15:29 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static t_list	*init_enemy_coords(char	**map)
{
	int		x;
	int		y;
	t_list	*enemy_coords;

	x = 0;
	y = 0;
	enemy_coords = NULL;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'X')
				ft_lstadd_front(&enemy_coords, ft_lstnew(x, y));
			x++;
		}
		x = 0;
		y++;
	}
	return (enemy_coords);
}

void	init_game(t_game *game, t_coordinate map_size)
{
	game->img_size = 75;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->img_size * (map_size.x - 1), \
							game->img_size * map_size.y, "so_long");
	game->background = init_textures(game->mlx, "textures/background.xpm");
	game->wall = init_textures(game->mlx, "textures/wall.xpm");
	init_player_textures(game);
	init_enemy_textures(game);
	init_nums_textures(game);
	game->collectible = init_textures(game->mlx, "textures/collectible.xpm");
	game->map_exit = init_textures(game->mlx, "textures/exit.xpm");
	game->player_position = search_player_position(game->map);
	game->player.last_operation = 3;
	game->enemy_coords = init_enemy_coords(game->map);
}

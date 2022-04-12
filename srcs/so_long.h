/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:21:14 by vjose             #+#    #+#             */
/*   Updated: 2021/11/02 18:21:14 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <unistd.h>

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_coordinate
{
	int	x;
	int	y;
}t_coordinate;

typedef struct s_cep
{
	int	collectible;
	int	exit;
	int	player;
}t_cep;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	int				img_size;
	t_data			background;
	t_data			wall;
	t_data			player;
	t_data			collectible;
	t_data			map_exit;
	t_coordinate	player_position;
	t_cep			cep;
	char			**map;
}t_game;

void			map_allocation(char *argv, t_game *game, \
								t_coordinate *map_size);
void			find_map_size(char *argv, t_coordinate *map_size);
int				open_file(char *argv);
void			check_map(t_game *game, t_coordinate *map_size);
int				check_cep(t_game *game);
void			init_game(t_game *game, t_coordinate map_size);
void			init_variables(t_cep *cep);
t_coordinate	search_player_position(char **map);
void			move_player(t_game *game, int x, int y);
int				close_win(t_game *game);
void			put_image_to_window(t_game *game, void *img, int x, int y);

//errors
void			error_invalid_file(void);
void			error_read(int fd);
void			error_empty_map(void);
void			error_wrong_border(void);
void			error_invlaid_texture(void);
void			error_wrong_cep(void);
void			error_allocation(void);
void			error_wrong_params(void);
void			error_not_xpm(void);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:02:48 by vjose             #+#    #+#             */
/*   Updated: 2021/12/19 20:02:48 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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

typedef struct s_list
{
	int				x;
	int				y;
	char			direction;
	struct s_list	*next;
}	t_list;

typedef struct s_data_enemy
{
	t_data			up;
	t_data			down;
}	t_data_enemy;

typedef struct s_data_player
{
	t_data			up_1;
	t_data			up_2;
	t_data			down_1;
	t_data			down_2;
	t_data			right_1;
	t_data			right_2;
	t_data			left_1;
	t_data			left_2;
	int				last_operation;
}	t_data_player;

typedef struct s_data_steps
{
	t_data			num_0;
	t_data			num_1;
	t_data			num_2;
	t_data			num_3;
	t_data			num_4;
	t_data			num_5;
	t_data			num_6;
	t_data			num_7;
	t_data			num_8;
	t_data			num_9;
}	t_data_steps;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	int				img_size;
	t_coordinate	player_position;
	t_data			background;
	t_data			wall;
	t_data			collectible;
	t_data			map_exit;
	t_cep			cep;
	t_data_player	player;
	t_data_enemy	enemy;
	t_data_steps	steps;
	t_list			*enemy_coords;
	char			**map;
}t_game;

void			map_allocation(char *argv, t_game *game, \
								t_coordinate *map_size);
void			find_map_size(char *argv, t_coordinate *map_size);
int				open_file(char *argv);
void			check_map(t_game *game, t_coordinate *map_size);
void			init_game(t_game *game, t_coordinate map_size);
t_data			init_textures(void *mlx, char *filename);
void			init_nums_textures(t_game *game);
void			init_player_textures(t_game *game);
void			init_enemy_textures(t_game *game);
void			init_variables(t_cep *cep);
t_list			*ft_lstnew(int x, int y);
void			ft_lstadd_front(t_list **lst, t_list *new);
t_coordinate	search_player_position(char **map);
void			print_counter(t_game *game, int steps);
void			next_step(t_game *game, int x, int y);
int				do_step(t_game *game, int x, int y, t_coordinate pos);
void			move_player(t_game *game, t_coordinate pos, int x, int y);
void			move_enemy(t_game *game);
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
void			error_counter_so_big(void);
#endif
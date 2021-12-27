/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:00:41 by vjose             #+#    #+#             */
/*   Updated: 2021/12/17 22:17:07 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

void	put_image_to_window(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, \
							game->img_size * x, game->img_size * y);
}

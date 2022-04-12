/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:37:10 by vjose             #+#    #+#             */
/*   Updated: 2021/12/23 18:28:55 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	print_step(t_game *game, int tmp, int x)
{
	if (tmp == 0)
		put_image_to_window(game, game->steps.num_0.img, x, 0);
	else if (tmp == 1)
		put_image_to_window(game, game->steps.num_1.img, x, 0);
	else if (tmp == 2)
		put_image_to_window(game, game->steps.num_2.img, x, 0);
	else if (tmp == 3)
		put_image_to_window(game, game->steps.num_3.img, x, 0);
	else if (tmp == 4)
		put_image_to_window(game, game->steps.num_4.img, x, 0);
	else if (tmp == 5)
		put_image_to_window(game, game->steps.num_5.img, x, 0);
	else if (tmp == 6)
		put_image_to_window(game, game->steps.num_6.img, x, 0);
	else if (tmp == 7)
		put_image_to_window(game, game->steps.num_7.img, x, 0);
	else if (tmp == 8)
		put_image_to_window(game, game->steps.num_8.img, x, 0);
	else if (tmp == 9)
		put_image_to_window(game, game->steps.num_9.img, x, 0);
}

static size_t	ft_size(int n)
{
	size_t	size;

	size = 1;
	while (n > 9)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

static int	ft_pow(size_t size)
{
	int	i;

	i = 1;
	while (size > 0)
	{
		i = i * 10;
		size--;
	}
	return (i);
}

void	print_counter(t_game *game, int steps)
{
	int	i;
	int	size;

	size = ft_size(steps);
	if (game->map[0][size - 1] == '\n')
		error_counter_so_big();
	i = 0;
	while (i < size)
	{
		print_step(game, (steps / ft_pow(size - i - 1)) % 10, i);
		i++;
	}
}

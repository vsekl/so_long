/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:37:33 by vjose             #+#    #+#             */
/*   Updated: 2021/12/16 19:37:33 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_invalid_file(void)
{
	perror("Invalid map");
	exit(0);
}

void	error_read(int fd)
{
	perror("Invalid read");
	close(fd);
	exit(0);
}

void	error_empty_map(void)
{
	printf("Invalid map: Empty map\n");
	exit(0);
}

void	error_allocation(void)
{
	perror("Map allocation error");
	exit(0);
}

void	error_wrong_border(void)
{
	printf("Invalid map: Wrong border or border textures\n");
	exit(0);
}

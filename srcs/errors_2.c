/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:15:00 by vjose             #+#    #+#             */
/*   Updated: 2021/12/23 20:17:59 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_wrong_cep(void)
{
	printf("Invalid map: wrong amount of CEP textures or invalid textures\n");
	exit(0);
}

void	error_wrong_params(void)
{
	printf("Invalid input: Wrong number of parameters!\n");
	exit(0);
}

void	error_not_xpm(void)
{
	printf("Invalid xpm file!\n");
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:37:11 by vjose             #+#    #+#             */
/*   Updated: 2021/12/23 21:27:44 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	error_counter_so_big(void)
{
	printf("Counter is too big!\n");
	exit(0);
}

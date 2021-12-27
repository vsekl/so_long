/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:33:25 by vjose             #+#    #+#             */
/*   Updated: 2021/12/21 19:16:32 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_list	*ft_lstnew(int x, int y)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (elem == 0 )
		return (NULL);
	elem->next = NULL;
	elem->x = x;
	elem->y = y;
	elem->direction = 'w';
	return (elem);
}

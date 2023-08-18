/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:36:15 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/19 01:39:01 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door.h"

t_door	*door_create(const int i, const int j, const double angle)
{
	t_door *const	door = malloc(sizeof(t_door));

	if (door == NULL)
		return (NULL);
	door->i = i;
	door->j = j;
	door->angle = angle;
	return (door);
}

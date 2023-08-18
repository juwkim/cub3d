/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:36:15 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/19 02:55:31 by juwkim           ###   ########.fr       */
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
	door->b_update = false;
	return (door);
}

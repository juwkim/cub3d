/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:36:15 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:40:13 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_bonus.h"

t_door	*door_create(const int i, const int j, const int angle)
{
	t_door *const	door = malloc(sizeof(t_door));

	if (door == NULL)
		return (NULL);
	door->i = i;
	door->j = j;
	door->angle = angle;
	door->angle_closed = angle;
	door->angle_target = angle;
	return (door);
}

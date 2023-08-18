/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:03:21 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/19 03:03:39 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door.h"
#include "window.h"

bool	door_update(t_cub3d *const cub3d)
{
	t_list_node		*cur;
	t_door			*door;

	cur = cub3d->doors.head->next;
	while (cur != NULL)
	{
		door = cur->item;
		if (door->b_update)
			printf("door %d %d updated\n", door->i, door->j);
		cur = cur->next;
	}
	return (true);
}

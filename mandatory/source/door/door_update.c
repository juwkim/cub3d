/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:03:21 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 00:38:10 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door.h"
#include "window.h"

bool	door_update(t_cub3d *const cub3d)
{
	t_list_node		*cur;
	t_door			*door;
	bool			updated;
	int				door_idx;

	updated = false;
	cur = cub3d->doors.head->next;
	door_idx = 0;
	while (cur != NULL)
	{
		door = cur->item;
		if (door->angle != door->angle_target)
		{
			door_remove_map(cub3d, door);
			if (door->angle > door->angle_target)
				door->angle--;
			else
				door->angle++;
			door_render_map(cub3d, door, door_idx);
			updated = true;
		}
		cur = cur->next;
		++door_idx;
	}
	return (updated);
}

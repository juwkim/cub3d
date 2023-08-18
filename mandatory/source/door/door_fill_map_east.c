/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_fill_map_east.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:36:28 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/19 01:44:48 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door.h"

void	door_fill_map_east(t_cub3d *const cub3d, int i, const int j)
{
	int				off;
	t_map *const	map = &cub3d->map;

	off = 0;
	while (off < TEX_HEIGHT / 2)
	{
		map->tex_id[i][j] = T_DOOR;
		map->off[i][j] = off;
		map->door_idx[i][j] = cub3d->doors.size;
		++i;
		++off;
	}
	list_push_back(&cub3d->doors, door_create(i, j, 0.0f));
	while (off < TEX_HEIGHT)
	{
		map->tex_id[i][j] = T_DOOR;
		map->off[i][j] = off;
		map->door_idx[i][j] = cub3d->doors.size;
		++i;
		++off;
	}
	list_push_back(&cub3d->doors, door_create(i + TEX_HEIGHT - 1, j, M_PI));
}

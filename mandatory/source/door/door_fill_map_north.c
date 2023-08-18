/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_fill_map_north.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:36:28 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/19 02:50:21 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door.h"

void	door_fill_map_north(t_cub3d *const cub3d, const int i, int j)
{
	int				off;
	t_map *const	map = &cub3d->map;

	list_push_back(&cub3d->doors, door_create(i, j, M_PI_2));
	list_push_back(&cub3d->doors, door_create(i, j + TEX_WIDTH - 1, \
		M_PI + M_PI_2));
	off = 0;
	while (off < TEX_WIDTH / 2)
	{
		map->tex_id[i][j] = T_DOOR;
		map->off[i][j] = off;
		map->door_idx[i][j] = cub3d->doors.size - 2;
		++j;
		++off;
	}
	while (off < TEX_WIDTH)
	{
		map->tex_id[i][j] = T_DOOR;
		map->off[i][j] = off;
		map->door_idx[i][j] = cub3d->doors.size - 1;
		++j;
		++off;
	}
}

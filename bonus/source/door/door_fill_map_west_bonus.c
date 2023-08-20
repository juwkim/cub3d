/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_fill_map_west.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:36:28 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:40:37 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_bonus.h"

void	door_fill_map_west(t_cub3d *const cub3d, int i, const int j)
{
	int				off;
	t_map *const	map = &cub3d->map;

	list_push_back(&cub3d->doors, door_create(i, j, 0));
	list_push_back(&cub3d->doors, door_create(i + TEX_HEIGHT - 1, j, 180));
	off = TEX_HEIGHT - 1;
	while (off >= TEX_HEIGHT / 2)
	{
		map->tex_id[i][j] = T_DOOR;
		map->off[i][j] = off;
		map->door_idx[i][j] = cub3d->doors.size - 2;
		++i;
		--off;
	}
	while (off >= 0)
	{
		map->tex_id[i][j] = T_DOOR;
		map->off[i][j] = off;
		map->door_idx[i][j] = cub3d->doors.size - 1;
		++i;
		--off;
	}
}

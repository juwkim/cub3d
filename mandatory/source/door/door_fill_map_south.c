/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_fill_map_south.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:36:28 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/19 01:39:53 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door.h"

void	door_fill_map_south(t_cub3d *const cub3d, const int i, int j)
{
	int				off;
	t_map *const	map = &cub3d->map;

	off = TEX_WIDTH - 1;
	while (off >= 0)
	{
		map->tex_id[i][j] = T_DOOR;
		map->off[i][j] = off;
		++j;
		--off;
	}
}

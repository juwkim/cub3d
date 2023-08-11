/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_block_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:22:48 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 04:37:12 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "door.h"

static void	map_block_fill_wall(t_map *const map, int i, int j);
static void	map_block_fill_door(t_map *const map, int i, int j);

void	map_block_fill(t_map *const map, enum e_mapchar c, const int i, \
	const int j)
{
	if (c == C_WALL)
		map_block_fill_wall(map, i, j);
	else if (c == C_DOOR)
		map_block_fill_door(map, i, j);
}

static void	map_block_fill_wall(t_map *const map, int i, int j)
{
	map_block_fill_south(map, T_SOUTH, i, j);
	map_block_fill_east(map, T_EAST, i, j);
	map_block_fill_north(map, T_NORTH, i + TEX_HEIGHT - 1, j);
	map_block_fill_west(map, T_WEST, i, j + TEX_WIDTH - 1);
}

static void	map_block_fill_door(t_map *const map, int i, int j)
{
	const int	type = door_type(dlist_get_iterator(&map->list, \
		i / TEX_HEIGHT), j / TEX_WIDTH);

	if (type == 0)
	{
		map_block_fill_south(map, T_DOOR, i, j);
		map_block_fill_north(map, T_DOOR, i + TEX_HEIGHT - 1, j);
	}
	else if (type == 1)
	{
		map_block_fill_east(map, T_DOOR, i, j);
		map_block_fill_west(map, T_DOOR, i, j + TEX_WIDTH - 1);
	}
}

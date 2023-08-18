/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_block_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:22:48 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/18 20:09:31 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "door.h"

static void	map_block_fill_wall(t_cub3d *const cub3d, int i, int j);
static void	map_block_fill_door(t_cub3d *const cub3d, int i, int j);

void	map_block_fill(t_cub3d *const cub3d, enum e_mapchar c, const int i, \
	const int j)
{
	if (c == C_WALL || c == C_EMPTY)
		map_block_fill_wall(cub3d, i, j);
	else if (c == C_DOOR)
		map_block_fill_door(cub3d, i, j);
}

static void	map_block_fill_wall(t_cub3d *const cub3d, int i, int j)
{
	map_block_fill_south(cub3d, T_SOUTH, i, j);
	map_block_fill_east(cub3d, T_EAST, i, j);
	map_block_fill_north(cub3d, T_NORTH, i + TEX_HEIGHT - 1, j);
	map_block_fill_west(cub3d, T_WEST, i, j + TEX_WIDTH - 1);
}

static void	map_block_fill_door(t_cub3d *const cub3d, int i, int j)
{
	const int	type = door_type(dlist_get_iterator(&cub3d->map.list, \
		i / TEX_HEIGHT), j / TEX_WIDTH);

	if (type == 0)
	{
		map_block_fill_south(cub3d, T_DOOR, i, j);
		map_block_fill_north(cub3d, T_DOOR, i + TEX_HEIGHT - 1, j);
	}
	else if (type == 1)
	{
		map_block_fill_east(cub3d, T_DOOR, i, j);
		map_block_fill_west(cub3d, T_DOOR, i, j + TEX_WIDTH - 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_block_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:22:48 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/19 01:17:39 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "wall.h"
#include "door.h"

void	map_fill(t_cub3d *const cub3d, enum e_mapchar c, const int i, \
	const int j)
{
	if (c == C_WALL || c == C_EMPTY)
		wall_fill_map(cub3d, i, j);
	else if (c == C_DOOR)
		door_fill_map(cub3d, i, j);
}

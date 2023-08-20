/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:22:48 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:41:59 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bonus.h"
#include "wall_bonus.h"
#include "door_bonus.h"
#include "item_bonus.h"

void	map_fill(t_cub3d *const cub3d, enum e_mapchar c, const int i, \
	const int j)
{
	if (c == C_WALL || c == C_EMPTY)
		wall_fill_map(cub3d, i, j);
	else if (c == C_DOOR)
		door_fill_map(cub3d, i, j);
	else if (c == C_ITEM)
		item_fill_map(cub3d, i, j);
}

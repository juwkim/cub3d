/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_fill_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:22:48 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:40:40 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_bonus.h"

void	door_fill_map(t_cub3d *const cub3d, int i, int j)
{
	const int		type = door_type(dlist_get_iterator(&cub3d->map.list, \
		i / TEX_HEIGHT), j / TEX_WIDTH);

	if (type == 0)
	{
		door_fill_map_south(cub3d, i, j);
		door_fill_map_north(cub3d, i + TEX_HEIGHT - 1, j);
	}
	else if (type == 1)
	{
		door_fill_map_east(cub3d, i, j);
		door_fill_map_west(cub3d, i, j + TEX_WIDTH - 1);
	}
}

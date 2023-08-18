/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_fill_map_west.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:36:28 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/19 01:46:33 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wall.h"

void	wall_fill_map_west(t_cub3d *const cub3d, int i, const int j)
{
	int				off;
	t_map *const	map = &cub3d->map;

	off = TEX_HEIGHT - 1;
	while (off >= 0)
	{
		map->tex_id[i][j] = T_WEST;
		map->off[i][j] = off;
		++i;
		--off;
	}
}

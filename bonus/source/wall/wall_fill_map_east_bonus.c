/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_fill_map_east.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:36:28 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:44:00 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wall_bonus.h"

void	wall_fill_map_east(t_cub3d *const cub3d, int i, const int j)
{
	int				off;
	t_map *const	map = &cub3d->map;

	off = 0;
	while (off < TEX_HEIGHT)
	{
		map->tex_id[i][j] = T_EAST;
		map->off[i][j] = off;
		++i;
		++off;
	}
}

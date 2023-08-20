/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_fill_map_north.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:36:28 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:44:03 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wall_bonus.h"

void	wall_fill_map_north(t_cub3d *const cub3d, const int i, int j)
{
	int				off;
	t_map *const	map = &cub3d->map;

	off = 0;
	while (off < TEX_WIDTH)
	{
		map->tex_id[i][j] = T_NORTH;
		map->off[i][j] = off;
		++j;
		++off;
	}
}

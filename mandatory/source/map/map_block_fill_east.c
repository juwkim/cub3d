/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_block_fill_east.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:36:28 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/18 20:13:14 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	map_block_fill_east(t_cub3d *const cub3d, const enum e_texture tex, \
	int i, const int j)
{
	int				off;
	t_map *const	map = &cub3d->map;

	off = 0;
	while (off < TEX_HEIGHT)
	{
		map->tex_id[i][j] = tex;
		map->off[i][j] = off;
		++i;
		++off;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_block_fill_north.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:36:28 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/18 20:13:23 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	map_block_fill_north(t_cub3d *const cub3d, const enum e_texture tex, \
	const int i, int j)
{
	int				off;
	t_map *const	map = &cub3d->map;

	off = 0;
	while (off < TEX_WIDTH)
	{
		map->tex_id[i][j] = tex;
		map->off[i][j] = off;
		++j;
		++off;
	}
}

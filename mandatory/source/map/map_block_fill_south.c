/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_block_fill_south.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:36:28 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/18 20:13:29 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	map_block_fill_south(t_cub3d *const cub3d, const enum e_texture tex, \
	const int i, int j)
{
	int				off;
	t_map *const	map = &cub3d->map;

	off = TEX_WIDTH - 1;
	while (off >= 0)
	{
		map->tex_id[i][j] = tex;
		map->off[i][j] = off;
		++j;
		--off;
	}
}

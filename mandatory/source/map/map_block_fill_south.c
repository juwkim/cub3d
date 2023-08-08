/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_block_fill_south.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:36:28 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/08 20:45:55 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	map_block_fill_south(t_map *const map, const enum e_texture tex, \
	const int i, int j)
{
	int	off;

	off = TEX_WIDTH - 1;
	while (off >= 0)
	{
		map->tex_id[i][j] = tex;
		map->off[i][j] = off;
		++j;
		--off;
	}
}

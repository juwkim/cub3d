/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_block_fill_north.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:36:28 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/08 20:46:38 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	map_block_fill_north(t_map *const map, const enum e_texture tex, \
	const int i, int j)
{
	int	off;

	off = 0;
	while (off < TEX_WIDTH)
	{
		map->tex_id[i][j] = tex;
		map->off[i][j] = off;
		++j;
		++off;
	}
}
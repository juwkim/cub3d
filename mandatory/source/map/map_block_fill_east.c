/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_block_fill_east.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:36:28 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/08 20:46:19 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	map_block_fill_east(t_map *const map, const enum e_texture tex, \
	int i, const int j)
{
	int	off;

	off = 0;
	while (off < TEX_HEIGHT)
	{
		map->tex_id[i][j] = tex;
		map->off[i][j] = off;
		++i;
		++off;
	}
}

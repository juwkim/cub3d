/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_block_fill_west.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:36:28 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/08 20:46:52 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	map_block_fill_west(t_map *const map, const enum e_texture tex, \
	int i, const int j)
{
	int	off;

	off = TEX_HEIGHT - 1;
	while (off >= 0)
	{
		map->tex_id[i][j] = tex;
		map->off[i][j] = off;
		++i;
		--off;
	}
}

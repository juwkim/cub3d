/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:35:10 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:42:25 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap_bonus.h"
#include "image_bonus.h"

void	minimap_fill(t_minimap *const minimap, const t_map *const map, \
	int i, int j)
{
	const t_color	color = minimap_color(minimap, map, i, j);
	int				x;
	int				y;
	int				minimap_i;
	int				minimap_j;

	x = 0;
	while (x < TEX_HEIGHT)
	{
		minimap_i = (i + x) * minimap->height / map->height;
		y = 0;
		while (y < TEX_WIDTH)
		{
			minimap_j = (j + y) * minimap->width / map->width;
			*image_address(&minimap->img, minimap_i, minimap_j) = color;
			++y;
		}
		++x;
	}
}

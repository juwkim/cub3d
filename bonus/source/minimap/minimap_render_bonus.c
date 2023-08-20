/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:48:23 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:42:38 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap_bonus.h"
#include "image_bonus.h"

void	minimap_render(t_minimap *const minimap, const t_map *const map, \
	const t_camera *const cam)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			minimap_fill(minimap, map, i, j);
			j += TEX_WIDTH;
		}
		i += TEX_HEIGHT;
	}
	minimap_render_camera(minimap, map, (int)cam->i, (int)cam->j);
}

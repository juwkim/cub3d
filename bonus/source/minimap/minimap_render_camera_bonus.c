/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_render_camera_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:56:39 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 19:42:14 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap_bonus.h"
#include "image_bonus.h"

void	minimap_render_camera(t_minimap *const minimap, const t_map *const map, \
	int cam_i, int cam_j)
{
	const t_color	color = minimap_rgb(minimap, 255, 0, 0);
	int				x;
	int				y;
	int				minimap_i;
	int				minimap_j;

	x = -TEX_HEIGHT / 2;
	while (x < TEX_HEIGHT / 2)
	{
		minimap_i = (cam_i + x) * minimap->height / map->height;
		y = -TEX_WIDTH / 2;
		while (y < TEX_WIDTH / 2)
		{
			minimap_j = (cam_j + y) * minimap->width / map->width;
			if (*image_address(&minimap->img, minimap_i, minimap_j) == \
				minimap_rgb(minimap, 255, 255, 255))
				*image_address(&minimap->img, minimap_i, minimap_j) = color;
			++y;
		}
		++x;
	}
	minimap->cam_i = cam_i;
	minimap->cam_j = cam_j;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:03:33 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:20:59 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include "image.h"

bool	minimap_init(t_cub3d *const cub3d, const int alpha, void *mlx)
{
	t_minimap *const	minimap = &cub3d->minimap;
	t_map *const		map = &cub3d->map;
	t_camera *const		cam = &cub3d->cam;

	minimap->alpha = alpha;
	minimap->width = WIN_WIDTH / 4;
	minimap->height = WIN_HEIGHT / 4;
	if (image_init(&minimap->img, mlx, minimap->width, \
		minimap->height) == false)
		return (false);
	minimap_render(minimap, map, cam);
	return (true);
}

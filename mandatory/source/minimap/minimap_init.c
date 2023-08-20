/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:03:33 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 16:25:39 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include "image.h"

bool	minimap_init(t_minimap *const minimap, const t_map *const map, \
	const int alpha, void *mlx)
{
	minimap->alpha = alpha;
	minimap->width = WIN_WIDTH / 4;
	minimap->height = WIN_HEIGHT / 4;
	if (image_init(&minimap->img, mlx, minimap->width, \
		minimap->height) == false)
		return (false);
	minimap_render(minimap, map);
	return (true);
}

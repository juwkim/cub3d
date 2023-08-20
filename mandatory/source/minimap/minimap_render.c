/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:48:23 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 16:27:06 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include "image.h"

static t_color	minimap_color(const t_minimap *const minimap, \
	const t_map *const map, const int i, const int j);
static t_color	rgb(const t_minimap *const minimap, const unsigned int r, \
	const unsigned int g, const unsigned int b);

void	minimap_render(t_minimap *const minimap, const t_map *const map)
{
	int		i;
	int		j;
	t_color	color;

	i = 0;
	while (i < minimap->height)
	{
		j = 0;
		while (j < minimap->width)
		{
			color = minimap_color(minimap, map, \
				i * map->height / minimap->height, \
				j * map->width / minimap->width);
			*image_address(&minimap->img, i, j) = color;
			++j;
		}
		++i;
	}
}

static t_color	minimap_color(const t_minimap *const minimap, \
	const t_map *const map, const int i, const int j)
{
	if (map->tex_id[i][j] == T_DOOR)
		return (rgb(minimap, 0, 0, 100));
	else if (map->tex_id[i][j] == T_ITEM)
		return (rgb(minimap, 0, 100, 0));
	else if (map->tex_id[i][j] == T_SPACE)
		return (rgb(minimap, 255, 255, 255));
	else
		return (rgb(minimap, 100, 100, 100));
}

static t_color	rgb(const t_minimap *const minimap, const unsigned int r, \
	const unsigned int g, const unsigned int b)
{
	const t_color	color = (minimap->alpha << 24) | (r << 16) | (g << 8) | b;

	return (color);
}

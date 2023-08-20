/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:40:18 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:42:20 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap_bonus.h"

t_color	minimap_color(const t_minimap *const minimap, \
	const t_map *const map, const int i, const int j)
{
	if (map->tex_id[i][j] == T_DOOR)
		return (minimap_rgb(minimap, 0, 0, 255));
	else if (map->tex_id[i + 20][j + 30] == T_ITEM)
		return (minimap_rgb(minimap, 0, 255, 0));
	else if (map->tex_id[i][j] == T_SPACE)
		return (minimap_rgb(minimap, 255, 255, 255));
	else
		return (minimap_rgb(minimap, 255, 127, 127));
}

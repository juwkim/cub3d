/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:45:54 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:42:43 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap_bonus.h"

void	minimap_update(t_minimap *const minimap, const t_map *const map, \
	const t_camera *const cam)
{
	minimap_remove_camera(minimap, map, minimap->cam_i, minimap->cam_j);
	minimap_render_camera(minimap, map, (int)cam->i, (int)cam->j);
}

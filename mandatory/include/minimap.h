/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:50:33 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:29:16 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3d.h"

bool	minimap_init(t_cub3d *const cub3d, const int alpha, void *mlx);
void	minimap_destroy(const t_minimap *const minimap, void *mlx);
void	minimap_update(t_minimap *const minimap, const t_map *const map, \
	const t_camera *const cam);
void	minimap_render(t_minimap *const minimap, const t_map *const map, \
	const t_camera *const cam);
void	minimap_fill(t_minimap *const minimap, const t_map *const map, \
	int i, int j);
void	minimap_render_camera(t_minimap *const minimap, const t_map *const map, \
	int cam_i, int cam_j);
void	minimap_remove_camera(t_minimap *const minimap, const t_map *const map, \
	int cam_i, int cam_j);
t_color	minimap_color(const t_minimap *const minimap, \
	const t_map *const map, const int i, const int j);
t_color	minimap_rgb(const t_minimap *const minimap, const unsigned int r, \
	const unsigned int g, const unsigned int b);

#endif // __MINIMAP_H__

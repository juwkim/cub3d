/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:50:33 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 16:25:36 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3d.h"

bool	minimap_init(t_minimap *const minimap, const t_map *const map, \
	const int alpha, void *mlx);
void	minimap_destroy(const t_minimap *const minimap, void *mlx);
void	minimap_render(t_minimap *const minimap, const t_map *const map);

#endif // __MINIMAP_H__

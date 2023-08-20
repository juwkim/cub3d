/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:00:21 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:45:11 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

# include "cub3d_bonus.h"

bool	map_init(t_map *const map);
void	map_destroy(t_map *const map);
bool	map_parse(t_cub3d *const cub3d, const int fd);
bool	map_is_valid(const t_map *const map, const t_texture *const tex);
bool	map_is_boundary(const t_map *const map, const t_dlist_node *const cur, \
	const int i);
bool	map_has_texture(const t_texture *const tex, const char c);

bool	map_list_to_array(t_cub3d *const cub3d, t_map *const map);
void	map_fill(t_cub3d *const cub3d, enum e_mapchar c, const int i, \
	const int j);
void	map_trim(t_map *const map);

#endif // __MAP_BONUS_H__

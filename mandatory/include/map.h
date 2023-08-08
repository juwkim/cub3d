/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:00:21 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/08 21:24:34 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "cub3d.h"

bool	map_init(t_map *const map);
void	map_destroy(t_map *const map);
bool	map_parse(t_map *const map, t_camera *const cam, const int fd);
bool	map_is_valid(const t_map *const map);
bool	map_list_to_array(t_map *const map);
void	map_block_fill(t_map *const map, enum e_mapchar c, const int i, \
	const int j);
void	map_block_fill_south(t_map *const map, const enum e_texture tex, \
	const int i, int j);
void	map_block_fill_east(t_map *const map, const enum e_texture tex, \
	int i, const int j);
void	map_block_fill_north(t_map *const map, const enum e_texture tex, \
	const int i, int j);
void	map_block_fill_west(t_map *const map, const enum e_texture tex, \
	int i, const int j);
void	map_trim(t_map *const map);

#endif // __MAP_H__

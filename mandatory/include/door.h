/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:03:36 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 02:24:07 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOR_H
# define DOOR_H

# include "cub3d.h"

bool	door_update(t_cub3d *const cub3d);
int		door_type(const t_dlist_node *const cur, const int i);
bool	door_is_valid(const t_dlist_node *const cur, const int i);
t_door	*door_create(const int i, const int j, const double angle);
void	door_fill_map(t_cub3d *const cub3d, int i, int j);
void	door_fill_map_east(t_cub3d *const cub3d, int i, const int j);
void	door_fill_map_north(t_cub3d *const cub3d, const int i, int j);
void	door_fill_map_south(t_cub3d *const cub3d, const int i, int j);
void	door_fill_map_west(t_cub3d *const cub3d, int i, const int j);
void	door_press(t_cub3d *const cub3d);
void	door_remove_map(t_cub3d *const cub3d, const t_door *const door);
void	door_render_map(t_cub3d *const cub3d, const t_door *const door, \
	const int door_idx);

int		_get_i(const t_door *const door, const int cnt, const int d);
int		_get_j(const t_door *const door, const int cnt, const int d);

#endif // __DOOR_H__

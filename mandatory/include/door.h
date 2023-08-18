/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:03:36 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/19 01:40:29 by juwkim           ###   ########.fr       */
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

#endif // __DOOR_H__

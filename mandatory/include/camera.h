/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:03:16 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/11 23:55:42 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "cub3d.h"

bool	camera_init(t_camera *const cam, const double aof);
void	camera_destroy(const t_camera *const cam);
bool	camera_update(t_cub3d *const cub3d);
bool	camera_rotate_by_mouse(t_camera *const cam, const t_window *const win, \
	const t_mouse *const mouse);
bool	camera_rotate_by_key(t_camera *const cam, const t_key *const key);
bool	camera_move_by_key(t_camera *const cam, const t_key *const key, \
	const t_map *const map, const t_texture *const tex);
void	camera_set(t_camera *const cam, t_map *const map);

#endif // __CAMERA_H__

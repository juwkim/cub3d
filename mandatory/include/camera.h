/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:03:16 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/05 18:58:28 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "cub3d.h"

bool	camera_init(t_camera *const cam, const double aof, \
	const double rotation_speed, const double moving_speed);
void	camera_destroy(const t_camera *const cam);
bool	camera_rotate_by_mouse(t_camera *const cam, const t_window *const win, \
	const t_mouse *const mouse);
bool	camera_rotate_by_key(t_camera *const cam, const t_key *const key);
bool	camera_move_by_key(t_camera *const cam, const t_key *const key, \
	const t_map *const map, const t_texture *const tex);

#endif // __CAMERA_H__

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 23:54:34 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/11 23:55:51 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

bool	camera_update(t_cub3d *const cub3d)
{
	bool	rotated_by_key;
	bool	rotated_by_mouse;
	bool	moved;

	if (cub3d->key.esc == true)
		cub3d_destroy(cub3d);
	rotated_by_key = camera_rotate_by_key(&cub3d->cam, &cub3d->key);
	rotated_by_mouse = camera_rotate_by_mouse(&cub3d->cam, &cub3d->win, \
		&cub3d->mouse);
	moved = camera_move_by_key(&cub3d->cam, &cub3d->key, &cub3d->map, \
		&cub3d->tex);
	return (rotated_by_key | rotated_by_mouse | moved);
}

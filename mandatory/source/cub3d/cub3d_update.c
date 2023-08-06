/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:19:54 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/07 02:29:26 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "camera.h"

bool	cub3d_update(t_cub3d *const cub3d)
{
	bool	rotated_by_key;
	bool	rotated_by_mouse;
	bool	moved;

	if (cub3d->key->esc == true)
		cub3d_end(cub3d);
	rotated_by_key = camera_rotate_by_key(cub3d->cam, cub3d->key);
	rotated_by_mouse = camera_rotate_by_mouse(cub3d->cam, cub3d->win, \
		cub3d->mouse);
	moved = camera_move_by_key(cub3d->cam, cub3d->key, cub3d->map, cub3d->tex);
	return (rotated_by_key | rotated_by_mouse | moved);
}

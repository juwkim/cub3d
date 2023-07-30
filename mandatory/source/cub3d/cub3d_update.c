/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:19:54 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/31 07:36:12 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "camera.h"

bool	cub3d_update(t_cub3d *const cub3d)
{
	bool	rotated;
	bool	moved;

	if (cub3d->key->esc == true)
		cub3d_end(cub3d);
	rotated = camera_rotate_by_key(cub3d->cam, cub3d->key) | \
		camera_rotate_by_mouse(cub3d->cam, cub3d->win, cub3d->mouse);
	moved = camera_move_by_key(cub3d->cam, cub3d->key, cub3d->map, cub3d->tex);
	return (rotated | moved);
}

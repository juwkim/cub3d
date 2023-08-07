/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 03:27:03 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/08 03:49:09 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "window.h"
#include "key.h"
#include "mouse.h"
#include "camera.h"
#include "texture.h"
#include "map.h"

int	cub3d_destroy(t_cub3d *const cub3d)
{
	if (cub3d->win.ptr != NULL)
		window_destroy(&cub3d->win, cub3d->mlx);
	if (cub3d->key.vertical)
		key_destroy(&cub3d->key);
	if (cub3d->mouse.rotation_speed)
		mouse_destroy(&cub3d->mouse);
	if (cub3d->cam.rotation_speed)
		camera_destroy(&cub3d->cam);
	if (cub3d->tex.barrior_dist)
		texture_destroy(&cub3d->tex, cub3d->mlx);
	if (cub3d->map.tex_id)
		map_destroy(&cub3d->map);
	exit(EXIT_SUCCESS);
	return (0);
}

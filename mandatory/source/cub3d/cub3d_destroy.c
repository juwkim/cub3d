/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 03:27:03 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/07 23:54:17 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "window.h"
#include "key.h"
#include "mouse.h"
#include "camera.h"
#include "texture.h"
#include "map.h"

void	cub3d_destroy(const t_cub3d *const cub3d)
{
	if (cub3d->win)
		window_destroy(cub3d->win, cub3d->mlx);
	if (cub3d->key)
		key_destroy(cub3d->key);
	if (cub3d->mouse)
		mouse_destroy(cub3d->mouse);
	if (cub3d->cam)
		camera_destroy(cub3d->cam);
	if (cub3d->tex)
		texture_destroy(cub3d->tex, cub3d->mlx);
	if (cub3d->map)
		map_destroy(cub3d->map);
}

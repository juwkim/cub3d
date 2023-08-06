/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:54:13 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/07 02:16:19 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "window.h"
#include "key.h"
#include "mouse.h"
#include "camera.h"
#include "texture.h"
#include "map.h"

bool	cub3d_init(t_cub3d *const cub3d)
{
	ft_bzero(cub3d, sizeof(t_cub3d));
	cub3d->mlx = mlx_init();
	if (cub3d->mlx == NULL)
		return (false);
	if (window_init(cub3d->win, cub3d->mlx) == false || \
		key_init(cub3d->key) == false || \
		mouse_init(cub3d->mouse, 0.00005f) == false || \
		camera_init(cub3d->cam, M_PI / 3.0f, M_PI / 1024.0f, 4.0f) == false || \
		texture_init(cub3d->tex, 15) == false || \
		map_init(cub3d->map) == false)
	{
		cub3d_destroy(cub3d);
		return (false);
	}
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 03:27:03 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/27 04:25:06 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	mlx_destroy_display(cub3d->mlx);
}

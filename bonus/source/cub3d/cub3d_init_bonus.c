/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:54:13 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:39:51 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "window_bonus.h"
#include "key_bonus.h"
#include "mouse_bonus.h"
#include "camera_bonus.h"
#include "texture_bonus.h"
#include "map_bonus.h"
#include "minimap_bonus.h"
#include "ray_bonus.h"

bool	cub3d_init(t_cub3d *const cub3d, const char *filename)
{
	const int	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		perror("Error\n");
		return (false);
	}
	cub3d->mlx = mlx_init();
	list_init(&cub3d->doors);
	list_init(&cub3d->items);
	if (cub3d->mlx == NULL || \
		key_init(&cub3d->key, M_PI / 128.0f, 4.0f) == false || \
		mouse_init(&cub3d->mouse, 0.00005f) == false || \
		camera_init(&cub3d->cam, M_PI / 3.0f) == false || \
		ray_init(&cub3d->ray, 1.0f, TEX_WIDTH) == false || \
		texture_init(&cub3d->tex, 15) == false || \
		map_init(&cub3d->map) == false || \
		texture_parse(&cub3d->tex, &cub3d->map, cub3d->mlx, fd) == false || \
		map_parse(cub3d, fd) == false || \
		minimap_init(cub3d, 64, cub3d->mlx) == false || \
		window_init(&cub3d->win, &cub3d->tex, cub3d->mlx) == false)
		cub3d_destroy(cub3d);
	close(fd);
	return (true);
}

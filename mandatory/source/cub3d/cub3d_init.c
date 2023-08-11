/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:54:13 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/11 23:46:29 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "window.h"
#include "key.h"
#include "mouse.h"
#include "camera.h"
#include "texture.h"
#include "map.h"
#include "ray.h"

bool	cub3d_init(t_cub3d *const cub3d, const char *filename)
{
	const int	fd = open(filename, O_RDONLY);
	bool		failed;

	if (fd == -1)
	{
		perror("Error\n");
		return (false);
	}
	ft_bzero(cub3d, sizeof(t_cub3d));
	cub3d->mlx = mlx_init();
	failed = cub3d->mlx == NULL || \
		window_init(&cub3d->win, cub3d->mlx) == false || \
		key_init(&cub3d->key, M_PI / 128.0f, 4.0f) == false || \
		mouse_init(&cub3d->mouse, 0.00005f) == false || \
		camera_init(&cub3d->cam, M_PI / 3.0f) == false || \
		texture_init(&cub3d->tex, 15) == false || \
		map_init(&cub3d->map) == false || \
		ray_init(&cub3d->ray, 0.5f, TEX_WIDTH) == false || \
		texture_parse(&cub3d->tex, &cub3d->map, cub3d->mlx, fd) == false || \
		map_parse(&cub3d->map, &cub3d->cam, fd) == false;
	if (failed == true)
		cub3d_destroy(cub3d);
	close(fd);
	return (!failed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:44:35 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 02:48:50 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "utils.h"

static double	norm(const double di, const double dj);

void	raycasting(t_cub3d *const cub3d, t_camera *const cam, \
	const double direction, t_raycast *raycast)
{
	const double	c = LR * cos(direction);
	const double	s = LR * sin(direction);
	double			i;
	double			j;
	double			dist;

	i = cam->pos.i + 0.5f;
	j = cam->pos.j + 0.5f;
	while (true)
	{
		i += c;
		j += s;
		if (cub3d->map.data[(int)i][(int)j].tex_id != SPACE)
			break ;
	}
	dist = norm(i - cam->pos.i, j - cam->pos.j) * cos(direction - cam->lookat);
	raycast->tex = &cub3d->tex[cub3d->map.data[(int)i][(int)j].tex_id];
	_assert(raycast->tex->img != NULL, "No image to render\n");
	raycast->off = cub3d->map.data[(int)i][(int)j].off;
	raycast->start = WIN_HEIGHT * 0.5f * (1 - BOF / dist);
	raycast->end = WIN_HEIGHT * 0.5f * (1 + BOF / dist);
}

static double	norm(const double di, const double dj)
{
	return (sqrt(di * di + dj * dj));
}

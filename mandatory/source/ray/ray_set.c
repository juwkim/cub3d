/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 01:39:12 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 01:48:47 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static double	norm(const double di, const double dj);

void	ray_set(t_cub3d *const cub3d, const double i, const double j)
{
	t_ray *const	ray = &cub3d->ray;
	const double	dist = norm(i - cub3d->cam.i, j - cub3d->cam.j) * \
		cos(cub3d->ray.angle - cub3d->cam.angle);
	const int		int_i = (int)round(i);
	const int		int_j = (int)round(j);

	ray->start = cub3d->win.height * (1 - ray->winfull_dist / dist) / 2.0f;
	ray->end = cub3d->win.height * (1 + ray->winfull_dist / dist) / 2.0f;
	ray->img = &cub3d->tex.img[cub3d->map.tex_id[int_i][int_j]];
	ray->off = cub3d->map.off[int_i][int_j];
}

static double	norm(const double di, const double dj)
{
	return (sqrt(di * di + dj * dj));
}

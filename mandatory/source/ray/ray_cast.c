/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:44:35 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/11 23:23:19 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static double	norm(const double di, const double dj);

void	ray_cast(t_ray *const ray, const t_camera *const cam, \
	const t_map *const map, const t_window *const win, \
	t_texture *const tex)
{
	const double	c = ray->lr * cos(ray->angle);
	const double	s = ray->lr * sin(ray->angle);
	double			i;
	double			j;
	double			dist;

	i = cam->i;
	j = cam->j;
	while (true)
	{
		i += c;
		j += s;
		if (map->tex_id[(int)round(i)][(int)round(j)] != T_SPACE)
			break ;
	}
	dist = norm(i - cam->i, j - cam->j) * cos(ray->angle - cam->angle);
	ray->start = (int)(win->height * (1 - ray->bof / dist) / 2.0f);
	ray->end = (int)(win->height * (1 + ray->bof / dist) / 2.0f);
	ray->img = &tex->img[map->tex_id[(int)round(i)][(int)round(j)]];
	ray->off = map->off[(int)round(i)][(int)round(j)];
}

static double	norm(const double di, const double dj)
{
	return (sqrt(di * di + dj * dj));
}

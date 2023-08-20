/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 04:25:55 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:43:00 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_bonus.h"
#include "utils_bonus.h"

bool	ray_cast_sprite(t_cub3d *const cub3d)
{
	const double	c = cub3d->ray.lr * cos(cub3d->ray.angle);
	const double	s = cub3d->ray.lr * sin(cub3d->ray.angle);
	double			i;
	double			j;

	i = cub3d->cam.i;
	j = cub3d->cam.j;
	while (true)
	{
		i += c;
		j += s;
		if (cub3d->map.tex_id[(int)round(i)][(int)round(j)] != T_SPACE)
			break ;
	}
	if (cub3d->map.tex_id[(int)round(i)][(int)round(j)] != T_ITEM)
		return (false);
	ray_set(cub3d, i, j);
	return (true);
}

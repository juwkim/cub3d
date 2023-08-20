/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:44:35 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:43:03 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_bonus.h"
#include "utils_bonus.h"

void	ray_cast(t_cub3d *const cub3d)
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
		if (cub3d->map.tex_id[(int)round(i)][(int)round(j)] != T_SPACE && \
			cub3d->map.tex_id[(int)round(i)][(int)round(j)] != T_ITEM)
			break ;
	}
	ray_set(cub3d, i, j);
}

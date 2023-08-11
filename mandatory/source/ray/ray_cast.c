/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:44:35 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 05:41:35 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "utils.h"

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
		if (cub3d->map.tex_id[_round(i)][_round(j)] != T_SPACE)
			break ;
	}
	ray_set(cub3d, i, j);
}

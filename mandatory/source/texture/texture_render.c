/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:28:05 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 01:33:33 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "ray.h"

void	texture_render(t_cub3d *const cub3d)
{
	int				i;
	int				j;
	t_color			*color_addr;
	t_ray *const	ray = &cub3d->ray;

	j = 0;
	while (j < WIN_WIDTH)
	{
		cub3d->ray.angle = cub3d->cam.angle + \
			cub3d->cam.aof / 2 - cub3d->cam.aof * j / cub3d->win.width;
		ray_cast(cub3d);
		i = ft_max(0, ray->start);
		while (i <= ft_min(WIN_HEIGHT, ray->end))
		{
			color_addr = image_address(ray->img, \
				(TEX_HEIGHT - 1) * (i - ray->start) / (ray->end - ray->start), \
				ray->off);
			*image_address(&cub3d->win.img, i, j) = *color_addr;
			++i;
		}
		++j;
	}
}

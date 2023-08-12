/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:28:05 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 05:52:49 by juwkim           ###   ########.fr       */
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
	t_camera *const	cam = &cub3d->cam;

	j = 0;
	while (j < WIN_WIDTH)
	{
		ray->angle = cam->angle + \
			cam->aof / 2 - cam->aof * j / cub3d->win.width;
		ray_cast(cub3d);
		i = ft_max(0, ray->start);
		while (i <= ft_min(WIN_HEIGHT - 1, ray->end))
		{
			color_addr = image_address(&cub3d->tex.img[ray->tex_id], \
				(TEX_HEIGHT - 1) * (i - ray->start) / (ray->end - ray->start), \
				ray->off);
			*image_address(&cub3d->win.img, i, j) = *color_addr;
			cub3d->win.tex_id[i][j] = ray->tex_id;
			++i;
		}
		++j;
	}
}

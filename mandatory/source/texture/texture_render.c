/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:28:05 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/11 23:23:08 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "ray.h"

void	texture_render(t_texture *const tex, t_window *const win, \
	t_camera *const cam, t_ray *const ray, const t_map *const map)
{
	int		i;
	int		j;
	t_color	*color_addr;

	j = 0;
	while (j < WIN_WIDTH)
	{
		ray->angle = cam->angle + cam->aof / 2 - cam->aof * j / win->width;
		ray_cast(ray, cam, map, win, tex);
		i = ft_max(0, ray->start);
		while (i <= ft_min(WIN_HEIGHT, ray->end))
		{
			color_addr = image_address(ray->img, \
				(TEX_HEIGHT - 1) * (i - ray->start) / (ray->end - ray->start), \
				ray->off);
			*image_address(&win->img, i, j) = *color_addr;
			++i;
		}
		++j;
	}
}

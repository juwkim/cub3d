/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:44:35 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/05 19:06:30 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

# define LR		0.5f
# define BOF	TEX_WIDTH

typedef struct s_raycast
{
	t_image	*tex;
	int		off;
	int		start;
	int		end;
}	t_raycast;


static double	norm(const double di, const double dj);

angle + AOF / 2 - AOF * j / WIN_WIDTH
void	camera_raycast(const t_camera *const cam)
{
	const double	c = LR * cos(direction);
	const double	s = LR * sin(direction);
	double			i;
	double			j;
	double			dist;

	i = cam->i;
	j = cam->j;
	while (true)
	{
		i += c;
		j += s;
		if (cub3d->map.data[(int)round(i)][(int)round(j)].tex_id != T_SPACE)
			break ;
	}
	dist = norm(i - cam->pos.i, j - cam->pos.j) * cos(direction - cam->angle);
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

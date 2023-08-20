/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_press.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 00:03:33 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:40:47 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_bonus.h"
#include "utils_bonus.h"

static int	door_to_cam_angle(const t_door *const door, \
	const t_camera *const cam);

void	door_press(t_cub3d *const cub3d)
{
	t_mouse *const	mouse = &cub3d->mouse;
	const int		door_idx = cub3d->win.door_idx[mouse->y][mouse->x];
	t_door *const	door = list_get_item(&cub3d->doors, door_idx);
	int				d_angle;

	if (door->angle == door->angle_closed)
	{
		d_angle = door_to_cam_angle(door, &cub3d->cam) - door->angle;
		while (d_angle < 0)
			d_angle += 360;
		if (d_angle >= 180)
			door->angle_target = door->angle + 90;
		else
			door->angle_target = door->angle - 90;
	}
	else
		door->angle_target = door->angle_closed;
}

static int	door_to_cam_angle(const t_door *const door, \
	const t_camera *const cam)
{
	const double	i = cam->i - door->i;
	const double	j = cam->j - door->j;

	if (i == 0.0f)
	{
		if (j > 0.0f)
			return (90);
		else
			return (270);
	}
	return (degree(atan2(j, i)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate_by_mouse.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:33:49 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/27 04:36:20 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

static bool	camera_rotatable_by_mouse(const t_window *const win, \
	const int x, const int y);

bool	camera_rotate_by_mouse(t_camera *const cam, const t_window *const win, \
	const t_mouse *const mouse)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(win->ptr, &x, &y);
	if (camera_rotatable_by_mouse(win, x, y) == false)
		return (false);
	cam->angle += (win->width / 2 - x) * mouse->rotation_speed;
	return (true);
}

static bool	camera_rotatable_by_mouse(const t_window *const win, \
	const int x, const int y)
{
	if ((0 <= y && y < win->height) == false)
		return (false);
	if ((win->width / 3 <= x && x < win->width * 2 / 3) == false)
		return (false);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate_by_mouse.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:33:49 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/11 23:37:12 by juwkim           ###   ########.fr       */
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
	if ((0 <= x && x < win->width * 1 / 3) || \
		(win->width * 2 / 3 <= x && x < win->width) == true)
		return (true);
	return (false);
}

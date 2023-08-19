/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate_by_mouse.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:33:49 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 01:35:45 by juwkim           ###   ########.fr       */
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

	if (mouse->window_rotatable == false)
		return (false);
	mlx_mouse_get_pos(win->ptr, &x, &y);
	if (camera_rotatable_by_mouse(win, x, y) == false)
		return (false);
	cam->angle += (win->width / 2 - x) * mouse->rotation_speed;
	return (true);
}

static bool	camera_rotatable_by_mouse(const t_window *const win, \
	const int x, const int y)
{
	if (x < 0 || x >= win->width)
		return (false);
	if (y < win->height / 3 || y >= win->height * 2 / 3)
		return (false);
	if ((win->width * 1 / 5 <= x && x < win->width * 4 / 5) == true)
		return (false);
	return (true);
}

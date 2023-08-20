/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 05:54:59 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 19:33:46 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse.h"
#include "door.h"

int	mouse_press(int keycode, int x, int y, t_cub3d *const cub3d)
{
	t_mouse *const	mouse = &cub3d->mouse;

	if (x < 0 || x >= cub3d->win.width || y < 0 || y >= cub3d->win.height)
		return (0);
	if (keycode == BUTTON1)
		mouse->left = true;
	else if (keycode == BUTTON2)
		mouse->right = true;
	else if (keycode == BUTTON3)
		mouse->scroll = true;
	else if (keycode == BUTTON4)
		mouse->scroll_up = true;
	else if (keycode == BUTTON5)
		mouse->scroll_down = true;
	mouse->x = x;
	mouse->y = y;
	if (mouse->left == true && cub3d->win.tex_id[mouse->y][mouse->x] == T_DOOR)
		door_press(cub3d);
	return (0);
}

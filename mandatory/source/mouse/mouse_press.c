/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 05:54:59 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/19 02:59:21 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse.h"
#include "window.h"

int	mouse_press(int keycode, int x, int y, t_cub3d *const cub3d)
{
	t_mouse *const	mouse = &cub3d->mouse;
	int				door_idx;

	if (x < 0 || x >= cub3d->win.width || y < 0 || y >= cub3d->win.height)
		return (0);
	if (keycode == Button1)
		mouse->left = true;
	else if (keycode == Button2)
		mouse->right = true;
	else if (keycode == Button3)
		mouse->scroll = true;
	else if (keycode == Button4)
		mouse->scroll_up = true;
	else if (keycode == Button5)
		mouse->scroll_down = true;
	mouse->x = x;
	mouse->y = y;
	if (mouse->left == true && cub3d->win.tex_id[mouse->y][mouse->x] == T_DOOR)
	{
		door_idx = cub3d->win.door_idx[mouse->y][mouse->x];
		((t_door *)list_get_item(&cub3d->doors, door_idx))->b_update = true;
	}
	return (0);
}

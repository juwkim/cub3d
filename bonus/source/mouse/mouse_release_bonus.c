/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 05:54:59 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 19:35:05 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse_bonus.h"
#include "window_bonus.h"

int	mouse_release(int keycode, int x, int y, t_cub3d *const cub3d)
{
	t_mouse *const	mouse = &cub3d->mouse;

	if (x < 0 || x >= cub3d->win.width || y < 0 || y >= cub3d->win.height)
		return (0);
	if (keycode == BUTTON1)
		mouse->left = false;
	else if (keycode == BUTTON2)
		mouse->right = false;
	else if (keycode == BUTTON3)
		mouse->scroll = false;
	else if (keycode == BUTTON4)
		mouse->scroll_up = false;
	else if (keycode == BUTTON5)
		mouse->scroll_down = false;
	mouse->x = x;
	mouse->y = y;
	return (0);
}

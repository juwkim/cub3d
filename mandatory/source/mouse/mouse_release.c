/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 05:54:59 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 14:54:22 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse.h"
#include "window.h"

int	mouse_release(int keycode, int x, int y, t_cub3d *const cub3d)
{
	t_mouse *const	mouse = &cub3d->mouse;

	if (keycode == Button1)
		mouse->left = false;
	else if (keycode == Button2)
		mouse->right = false;
	else if (keycode == Button3)
		mouse->scroll = false;
	else if (keycode == Button4)
		mouse->scroll_up = false;
	else if (keycode == Button5)
		mouse->scroll_down = false;
	mouse->x = x;
	mouse->y = y;
	return (0);
}

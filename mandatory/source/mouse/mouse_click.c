/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 05:54:59 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 14:31:52 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse.h"
#include "window.h"

int	mouse_press(int keycode, int x, int y, t_cub3d *const cub3d)
{
	window_texture_print(&cub3d->win, x, y);
	if (keycode == Button1)
		printf("MOUSE_LEFT_BUTTON\n");
	else if (keycode == Button2)
		printf("MOUSE_RIGHT_BUTTON\n");
	else if (keycode == Button3)
		printf("MOUSE_SCROLL_BUTTON\n");
	else if (keycode == Button4)
		printf("MOUSE_SCROLL_UP\n");
	else if (keycode == Button5)
		printf("MOUSE_SCROLL_DOWN\n");
	return (0);
}

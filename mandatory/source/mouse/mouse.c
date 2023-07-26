/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:33:49 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 11:39:28 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse.h"

bool	mouse_rotate(t_cub3d *const cub3d)
{
	int		x;
	int		y;

	mlx_mouse_get_pos(cub3d->mlx, cub3d->win.ptr, &x, &y);
	if (0 <= y && y < WIN_HEIGHT && ((0 <= x && x < WIN_WIDTH / 3) || \
		(WIN_WIDTH * 2 / 3 <= x && x < WIN_WIDTH)))
	{
		cub3d->cam.lookat += (WIN_WIDTH / 2 - x) * MOUSE_ROTATE_SPEED / WIN_HEIGHT;
		return (true);
	}
	return (false);
}

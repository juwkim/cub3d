/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:11:40 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/25 03:00:57 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"
#include "key.h"

static bool	key_rotate(const int rotation, double *const lookat);
static bool	mouse_rotate(t_config *const config);

bool	rotate(t_config *const config, const int rotation, double *const lookat)
{
	return (key_rotate(rotation, lookat) | mouse_rotate(config));
}

static bool	key_rotate(const int rotation, double *const lookat)
{
	if (rotation == KEY_RELESED)
		return (false);
	if (rotation == KEY_LEFT)
		*lookat += RT_SPEED;
	else if (rotation == KEY_RIGHT)
		*lookat -= RT_SPEED;
	if (*lookat >= 2 * M_PI)
		*lookat -= 2 * M_PI;
	else if (*lookat < 0)
		*lookat += 2 * M_PI;
	return (true);
}

static bool	mouse_rotate(t_config *const config)
{
	int		x;
	int		y;

	mlx_mouse_get_pos(config->mlx, config->win.ptr, &x, &y);
	if (0 <= y && y < WIN_HEIGHT && ((0 <= x && x < WIN_WIDTH / 3) || \
		(WIN_WIDTH * 2 / 3 <= x && x < WIN_WIDTH)))
	{
		config->cam.lookat += (WIN_WIDTH / 2 - x) * RT_SPEED / WIN_HEIGHT;
		return (true);
	}
	return (false);
}

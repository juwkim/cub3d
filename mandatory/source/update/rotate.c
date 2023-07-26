/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:11:40 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 11:35:23 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"
#include "key.h"
#include "mouse.h"

static bool	key_rotate(const int rotation, double *const lookat);

bool	rotate(t_cub3d *const cub3d, const int rotation, double *const lookat)
{
	return (key_rotate(rotation, lookat) | mouse_rotate(cub3d));
}

static bool	key_rotate(const int rotation, double *const lookat)
{
	if (rotation == KEY_RELESE)
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

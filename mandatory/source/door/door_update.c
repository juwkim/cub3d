/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:03:21 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/19 00:58:53 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door.h"
#include "window.h"

bool	door_update(t_cub3d *const cub3d)
{
	t_mouse *const	mouse = &cub3d->mouse;

	if (mouse->left == true && cub3d->win.tex_id[mouse->y][mouse->x] == T_DOOR)
		printf("DOOR %d\n", cub3d->win.door_idx[mouse->y][mouse->x]);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:03:21 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 15:04:45 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door.h"
#include "window.h"

bool	door_update(t_cub3d *const cub3d)
{
	t_mouse *const	mouse = &cub3d->mouse;
	static int		a = 0;

	if (mouse->left == true && cub3d->win.tex_id[mouse->y][mouse->x] == T_DOOR)
		printf("DOOR %d\n", a++);
	return (true);
}

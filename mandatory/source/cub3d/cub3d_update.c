/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:19:54 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 14:43:19 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "camera.h"
#include "door.h"
#include "item.h"

bool	cub3d_update(t_cub3d *const cub3d)
{
	const bool	cam_updated = camera_update(cub3d);
	const bool	door_updated = door_update(cub3d);

	return (cam_updated | door_updated);
}

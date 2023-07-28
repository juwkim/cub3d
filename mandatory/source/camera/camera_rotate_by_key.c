/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate_by_key.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 04:33:04 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/28 00:56:13 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

bool	camera_rotate_by_key(t_camera *const cam, const t_key *const key)
{
	if (key->rotation == KEY_RELESE)
		return (false);
	if (key->rotation == KEY_LEFT)
		cam->angle += cam->rotation_speed;
	else if (key->rotation == KEY_RIGHT)
		cam->angle -= cam->rotation_speed;
	return (true);
}

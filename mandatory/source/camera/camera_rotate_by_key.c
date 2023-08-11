/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate_by_key.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 04:33:04 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/11 23:45:01 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

bool	camera_rotate_by_key(t_camera *const cam, const t_key *const key)
{
	if (key->rotation == KEY_RELESE)
		return (false);
	if (key->rotation == KEY_LEFT)
		cam->angle += key->rotation_speed;
	else if (key->rotation == KEY_RIGHT)
		cam->angle -= key->rotation_speed;
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:59:40 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/08 03:12:29 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

bool	camera_init(t_camera *const cam, const double aof, \
	const double rotation_speed, const double moving_speed)
{
	cam->aof = aof;
	cam->rotation_speed = rotation_speed;
	cam->moving_speed = moving_speed;
	return (true);
}

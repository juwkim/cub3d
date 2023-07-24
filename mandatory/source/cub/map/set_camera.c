/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:45:26 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 17:59:28 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_camera(t_camera *const cam, char **const map, \
	const int i, const int j)
{
	map[i][j] = C_SPACE;
	cam->pos.i = TEX_HEIGHT * i + TEX_HEIGHT / 2;
	cam->pos.j = TEX_WIDTH * j + TEX_WIDTH / 2;
	if (map[i][j] == C_SOUTH)
		cam->lookat = 0.0f;
	else if (map[i][j] == C_EAST)
		cam->lookat = M_PI_2;
	else if (map[i][j] == C_NORTH)
		cam->lookat = M_PI;
	else if (map[i][j] == C_WEST)
		cam->lookat = M_PI + M_PI_2;
}

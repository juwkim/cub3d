/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:45:26 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/28 01:21:09 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	set_camera(t_camera *const cam, char **const map, \
	const int i, const int j)
{
	cam->pos.i = TEX_HEIGHT * i + TEX_HEIGHT / 2;
	cam->pos.j = TEX_WIDTH * j + TEX_WIDTH / 2;
	if (map[i][j] == C_SOUTH)
		cam->angle = 0.0f;
	else if (map[i][j] == C_EAST)
		cam->angle = M_PI_2;
	else if (map[i][j] == C_NORTH)
		cam->angle = M_PI;
	else if (map[i][j] == C_WEST)
		cam->angle = M_PI + M_PI_2;
	map[i][j] = C_SPACE;
}

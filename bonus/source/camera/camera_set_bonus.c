/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:08:35 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:39:29 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_bonus.h"

static void	camera_set_pos(t_camera *const cam, const int i, const int j);
static void	camera_set_angle(t_camera *const cam, const enum e_mapchar c);

void	camera_set(t_camera *const cam, t_map *const map)
{
	t_dlist_node	*cur;
	char			*line;
	int				i;
	int				j;

	cur = map->list.head->next;
	i = 0;
	while (cur != map->list.tail)
	{
		j = 0;
		line = cur->item;
		while (j < cur->size)
		{
			if (ft_strchr("SENW", line[j]))
			{
				camera_set_pos(cam, i, j);
				camera_set_angle(cam, line[j]);
				line[j] = C_SPACE;
				return ;
			}
			++j;
		}
		++i;
		cur = cur->next;
	}
}

static void	camera_set_pos(t_camera *const cam, const int i, const int j)
{
	cam->i = TEX_HEIGHT * i + TEX_HEIGHT / 2;
	cam->j = TEX_WIDTH * j + TEX_WIDTH / 2;
}

static void	camera_set_angle(t_camera *const cam, const enum e_mapchar c)
{
	if (c == C_SOUTH)
		cam->angle = 0.0f;
	else if (c == C_EAST)
		cam->angle = M_PI_2;
	else if (c == C_NORTH)
		cam->angle = M_PI;
	else if (c == C_WEST)
		cam->angle = M_PI + M_PI_2;
}

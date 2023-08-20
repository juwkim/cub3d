/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_render_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 00:12:48 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:40:54 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_bonus.h"
#include "utils_bonus.h"

void	door_render_map(t_cub3d *const cub3d, const t_door *const door, \
	const int door_idx)
{
	int	cnt;
	int	i;
	int	j;
	int	k;

	cnt = 0;
	while (cnt < TEX_WIDTH / 2)
	{
		k = -2;
		while (k <= 2)
		{
			i = _door_get_i(door, cnt, k);
			j = _door_get_j(door, cnt, k);
			if (cub3d->map.tex_id[i][j] == T_SPACE)
				cub3d->map.tex_id[i][j] = T_DOOR;
			cub3d->map.off[i][j] = cnt;
			cub3d->map.door_idx[i][j] = door_idx;
			++k;
		}
		++cnt;
	}
}

int	_door_get_i(const t_door *const door, const int cnt, const int d)
{
	double	i;

	i = door->i + cnt * cos(radian(door->angle));
	i += d * sin(radian(door->angle));
	return ((int)round(i));
}

int	_door_get_j(const t_door *const door, const int cnt, const int d)
{
	double	j;

	j = door->j + cnt * sin(radian(door->angle));
	j += d * cos(radian(door->angle));
	return ((int)round(j));
}

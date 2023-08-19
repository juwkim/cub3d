/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_remove_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 00:12:48 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 00:32:14 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door.h"
#include "utils.h"

void	door_remove_map(t_cub3d *const cub3d, const t_door *const door)
{
	const double	di = cos(radian(door->angle));
	const double	dj = sin(radian(door->angle));
	double			i;
	double			j;
	int				cnt;

	i = (double)door->i;
	j = (double)door->j;
	cnt = 0;
	while (cnt < TEX_WIDTH / 2)
	{
		cub3d->map.tex_id[(int)round(i)][(int)round(j)] = T_SPACE;
		i += di;
		j += dj;
		++cnt;
	}
}

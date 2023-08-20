/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_remove_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 00:12:48 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 04:56:31 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door.h"
#include "utils.h"

void	door_remove_map(t_cub3d *const cub3d, const t_door *const door)
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
			if (cub3d->map.tex_id[i][j] == T_DOOR)
				cub3d->map.tex_id[i][j] = T_SPACE;
			++k;
		}
		++cnt;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_render_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 04:46:48 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:41:37 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "item_bonus.h"
#include "utils_bonus.h"

void	item_render_map(t_cub3d *const cub3d, const t_item *const item)
{
	int	cnt;
	int	i;
	int	j;
	int	k;

	cnt = 0;
	while (cnt < TEX_WIDTH)
	{
		k = -3;
		while (k <= 3)
		{
			i = _item_get_i(item, cnt, k);
			j = _item_get_j(item, cnt, k);
			cub3d->map.tex_id[i][j] = T_ITEM;
			cub3d->map.off[i][j] = TEX_WIDTH / 2;
			++k;
		}
		++cnt;
	}
}

int	_item_get_i(const t_item *const item, const int cnt, const int k)
{
	double	i;

	i = item->i;
	i += (TEX_WIDTH / 6 + k) * cos(radian(item->angle + 360 * cnt / TEX_WIDTH));
	return ((int)round(i));
}

int	_item_get_j(const t_item *const item, const int cnt, const int k)
{
	double	j;

	j = item->j;
	j += (TEX_WIDTH / 6 + k) * sin(radian(item->angle + 360 * cnt / TEX_WIDTH));
	return ((int)round(j));
}

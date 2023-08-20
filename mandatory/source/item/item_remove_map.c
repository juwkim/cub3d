/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_remove_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 04:57:12 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 05:34:08 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "item.h"

void	item_remove_map(t_cub3d *const cub3d, const t_item *const item)
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
			i = _item_get_i(item, cnt - TEX_WIDTH / 2 + 1, k);
			j = _item_get_j(item, cnt - TEX_WIDTH / 2 + 1, k);
			cub3d->map.tex_id[i][j] = T_SPACE;
			++k;
		}
		++cnt;
	}
}

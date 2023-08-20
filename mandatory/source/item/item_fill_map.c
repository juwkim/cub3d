/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_fill_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 02:39:36 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 14:18:02 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "item.h"
#include "door.h"

void	item_fill_map(t_cub3d *const cub3d, int i, int j)
{
	t_item *const	item = item_create(i + TEX_HEIGHT / 2 - 1, \
		j + TEX_WIDTH / 2 - 1, 0);

	list_push_back(&cub3d->items, item);
	item_render_map(cub3d, item);
}

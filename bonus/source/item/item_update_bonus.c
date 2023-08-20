/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 05:00:29 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:41:39 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "item_bonus.h"

bool	item_update(t_cub3d *const cub3d)
{
	t_list_node		*cur;
	t_item			*item;

	cur = cub3d->items.head->next;
	while (cur != NULL)
	{
		item = cur->item;
		item_remove_map(cub3d, item);
		item_render_map(cub3d, item);
		cur = cur->next;
	}
	return (true);
}

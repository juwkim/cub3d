/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_boundary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 02:43:24 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 03:57:41 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

bool	map_is_boundary(const t_map *const map, const t_dlist_node *const cur, \
	const int i)
{
	const t_dlist *const	list = &map->list;

	if (cur->prev == list->head || cur->next == list->tail)
		return (true);
	if (i == 0 || cur->item[i + 1] == '\0')
		return (true);
	if (cur->item[i - 1] == C_EMPTY || cur->item[i + 1] == C_EMPTY)
		return (true);
	if (cur->prev->size <= i || cur->prev->item[i] == C_EMPTY)
		return (true);
	if (cur->next->size <= i || cur->next->item[i] == C_EMPTY)
		return (true);
	return (false);
}

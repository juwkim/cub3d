/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_is_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 04:02:13 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 04:10:13 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door.h"

bool	door_is_valid(const t_dlist_node *const cur, const int i)
{
	if (cur->prev->item[i] == C_SPACE && cur->next->item[i] == C_SPACE && \
		cur->item[i - 1] == C_WALL && cur->item[i + 1] == C_WALL)
		return (true);
	if (cur->prev->item[i] == C_WALL && cur->next->item[i] == C_WALL && \
		cur->item[i - 1] == C_SPACE && cur->item[i + 1] == C_SPACE)
		return (true);
	return (false);
}

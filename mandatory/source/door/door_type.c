/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 04:29:25 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 04:30:33 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door.h"

int	door_type(const t_dlist_node *const cur, const int i)
{
	if (cur->prev->item[i] == C_SPACE && cur->next->item[i] == C_SPACE && \
		cur->item[i - 1] == C_WALL && cur->item[i + 1] == C_WALL)
		return (0);
	if (cur->prev->item[i] == C_WALL && cur->next->item[i] == C_WALL && \
		cur->item[i - 1] == C_SPACE && cur->item[i + 1] == C_SPACE)
		return (1);
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_is_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 04:02:13 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:40:44 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_bonus.h"

bool	door_is_valid(const t_dlist_node *const cur, const int i)
{
	if (door_type(cur, i) == -1)
		return (false);
	return (true);
}

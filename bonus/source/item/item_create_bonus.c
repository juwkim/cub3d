/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 04:33:41 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:41:28 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "item_bonus.h"

t_item	*item_create(const int i, const int j, const int angle)
{
	t_item *const	item = malloc(sizeof(t_item));

	if (item == NULL)
		return (NULL);
	item->i = i;
	item->j = j;
	item->angle = angle;
	return (item);
}

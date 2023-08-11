/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_has_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 03:41:54 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 03:42:22 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

bool	map_has_texture(const t_texture *const tex, const char c)
{
	if (c == 'D' && tex->img[T_DOOR].ptr == NULL)
	{
		printf("Error\nDoor texture are omitted\n");
		return (false);
	}
	if (c == 'I' && tex->img[T_ITEM].ptr == NULL)
	{
		printf("Error\nItem texture are omitted\n");
		return (false);
	}
	return (true);
}

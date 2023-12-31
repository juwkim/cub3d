/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:54:53 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/08 14:11:59 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

bool	map_init(t_map *const map)
{
	map->tex_id = NULL;
	map->off = NULL;
	map->width = 0;
	map->height = 0;
	dlist_init(&map->list);
	return (true);
}

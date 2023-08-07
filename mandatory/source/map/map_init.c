/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:54:53 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/08 03:40:51 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

bool	map_init(t_map *const map)
{
	map->tex_id = NULL;
	map->off = NULL;
	map->width = 0;
	map->height = 0;
	list_init(&map->list);
	return (true);
}

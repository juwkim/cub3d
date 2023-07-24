/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:30:05 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 13:34:03 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "utils.h"

void	init_map(t_map *const map)
{
	map->capacity = DEFAULT_MAP_CAPACITY;
	map->board = (char **)malloc(sizeof(char *) * map->capacity);
	_assert(map->board != NULL, "malloc() failed\n");
}

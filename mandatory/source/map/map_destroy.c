/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 00:00:47 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/08 21:10:23 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	map_destroy(t_map *const map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->tex_id[i]);
		free(map->off[i]);
		++i;
	}
	free(map->tex_id);
	free(map->off);
	dlist_destroy(&map->list, free);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 00:00:47 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/07 22:32:20 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	map_destroy(t_map *map)
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
	free(map);
}

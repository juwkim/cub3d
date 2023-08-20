/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 00:00:47 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:41:52 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bonus.h"

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

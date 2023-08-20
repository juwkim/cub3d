/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_trim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:13:57 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:42:16 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bonus.h"
#include "texture_bonus.h"

static void	map_trim_upper(t_map *const map, const int i, const int j);
static void	map_trim_lower(t_map *const map, const int i, const int j);

void	map_trim(t_map *const map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (texture_is_wall(map->tex_id[i][j]) == true)
			{
				if (i > 0)
					map_trim_upper(map, i, j);
				if (i + TEX_HEIGHT < map->height)
					map_trim_lower(map, i, j);
			}
			j += TEX_WIDTH;
		}
		i += TEX_HEIGHT;
	}
}

static void	map_trim_upper(t_map *const map, const int i, const int j)
{
	if (map->tex_id[i - 1][j] == T_SPACE)
	{
		map->tex_id[i][j] = T_SOUTH;
		map->tex_id[i][j + TEX_WIDTH - 1] = T_SOUTH;
	}
	else
	{
		map->tex_id[i][j] = T_EAST;
		map->tex_id[i][j + TEX_WIDTH - 1] = T_WEST;
	}
}

static void	map_trim_lower(t_map *const map, const int i, const int j)
{
	if (map->tex_id[i + TEX_HEIGHT][j] == T_SPACE)
	{
		map->tex_id[i + TEX_HEIGHT - 1][j] = T_NORTH;
		map->tex_id[i + TEX_HEIGHT - 1][j + TEX_WIDTH - 1] = T_NORTH;
	}
	else
	{
		map->tex_id[i + TEX_HEIGHT - 1][j] = T_EAST;
		map->tex_id[i + TEX_HEIGHT - 1][j + TEX_WIDTH - 1] = T_WEST;
	}
}

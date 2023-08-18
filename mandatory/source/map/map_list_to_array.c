/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list_to_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:52:54 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/19 01:24:44 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static bool	map_init_array(t_map *const map);
static int	get_map_width(const t_map *const map);

bool	map_list_to_array(t_cub3d *const cub3d, t_map *const map)
{
	int						i;
	int						j;
	const t_dlist_node		*cur = map->list.head->next;
	char					*line;

	if (map_init_array(map) == false)
		return (false);
	i = 0;
	while (i < map->list.size)
	{
		j = 0;
		line = cur->item;
		while (j < map->width / TEX_WIDTH)
		{
			if (line[j])
				map_fill(cub3d, line[j], i * TEX_HEIGHT, j * TEX_WIDTH);
			else
				map_fill(cub3d, C_EMPTY, i * TEX_HEIGHT, j * TEX_WIDTH);
			++j;
		}
		++i;
		cur = cur->next;
	}
	map_trim(map);
	return (true);
}

static bool	map_init_array(t_map *const map)
{
	int	i;
	int	j;

	map->width = get_map_width(map) * TEX_WIDTH;
	map->height = map->list.size * TEX_HEIGHT;
	map->tex_id = malloc(map->height * sizeof(enum e_texture *));
	map->off = malloc(map->height * sizeof(uint8_t *));
	map->door_idx = malloc(map->height * sizeof(int *));
	if (map->tex_id == NULL || map->off == NULL || map->door_idx == NULL)
		return (false);
	i = 0;
	while (i < map->height)
	{
		map->tex_id[i] = malloc(map->width * sizeof(enum e_texture));
		map->off[i] = malloc(map->width * sizeof(uint8_t));
		map->door_idx[i] = malloc(map->width * sizeof(int));
		if (!map->tex_id[i] || !map->off[i] || !map->door_idx[i])
			return (false);
		j = 0;
		while (j < map->width)
			map->tex_id[i][j++] = T_SPACE;
		++i;
	}
	return (true);
}

static int	get_map_width(const t_map *const map)
{
	int						width;
	const t_dlist *const	list = &map->list;
	const t_dlist_node		*cur = list->head->next;

	width = 0;
	while (cur != list->tail)
	{
		width = ft_max(width, cur->size);
		cur = cur->next;
	}
	return (width);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:09:50 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 03:13:57 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static bool	map_is_valid_element(const t_map *const map, \
	const t_texture *const tex);
static bool	map_is_valid_camera(const t_map *const map);
static bool	map_is_valid_boundary(const t_map *const map);
static bool	map_has_texture(const t_texture *const tex, const char c);

bool	map_is_valid(const t_map *const map, const t_texture *const tex)
{
	if (map_is_valid_element(map, tex) == false)
		return (false);
	if (map_is_valid_camera(map) == false)
		return (false);
	if (map_is_valid_boundary(map) == false)
		return (false);
	return (true);
}

static bool	map_is_valid_element(const t_map *const map, \
	const t_texture *const tex)
{
	const t_dlist *const	list = &map->list;
	t_dlist_node			*cur;
	char					*line;

	cur = list->head->next;
	while (cur != list->tail)
	{
		line = cur->item;
		while (*line)
		{
			if (ft_strchr("SENWDI01 ", *line) == NULL)
			{
				printf("Error\nMap includes [%c]\n", *line);
				return (false);
			}
			if (map_has_texture(tex, *line) == false)
				return (false);
			++line;
		}
		cur = cur->next;
	}
	return (true);
}

static bool	map_is_valid_camera(const t_map *const map)
{
	t_dlist_node	*cur;
	char			*line;
	bool			b_cam;

	b_cam = false;
	cur = map->list.head->next;
	while (cur != map->list.tail)
	{
		line = cur->item;
		while (*line)
		{
			if (ft_strchr("SENW", *line))
			{
				if (b_cam == true)
				{
					printf("Error\nMap includes multiple camera\n");
					return (false);
				}
				b_cam = true;
			}
			++line;
		}
		cur = cur->next;
	}
	return (true);
}

static bool	map_is_valid_boundary(const t_map *const map)
{
	t_dlist_node	*cur;
	char			*line;
	int				i;

	cur = map->list.head->next;
	while (cur != map->list.tail)
	{
		line = cur->item;
		i = 0;
		while (i < cur->size)
		{
			if (ft_strchr("SENWDI0", line[i]) && \
				map_is_boundary(map, cur, i) == true)
			{
				printf("Error\nMap boundary includes [%c]\n", line[i]);
				return (false);
			}
			++i;
		}
		cur = cur->next;
	}
	return (true);
}

static bool	map_has_texture(const t_texture *const tex, const char c)
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

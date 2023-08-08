/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:09:50 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/08 14:58:24 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static bool	map_is_valid_element(const t_map *const map);
static bool	map_is_valid_camera(const t_map *const map);
static bool	map_is_valid_boundary(const t_map *const map);
static bool	map_is_boundary(const t_map *const map, \
	const t_dlist_node *const cur, const int i);

bool	map_is_valid(const t_map *const map)
{
	if (map_is_valid_element(map) == false)
		return (false);
	if (map_is_valid_camera(map) == false)
		return (false);
	if (map_is_valid_boundary(map) == false)
		return (false);
	return (true);
}

static bool	map_is_valid_element(const t_map *const map)
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

static bool	map_is_boundary(const t_map *const map, \
	const t_dlist_node *const cur, const int i)
{
	const t_dlist *const	list = &map->list;

	if (cur->prev == list->head || cur->next == list->tail)
		return (true);
	if (i == 0 || cur->item[i + 1] == '\0')
		return (true);
	if (cur->item[i - 1] == C_EMPTY || cur->item[i + 1] == C_EMPTY)
		return (true);
	if (cur->prev->size <= i || cur->prev->item[i] == C_EMPTY)
		return (true);
	if (cur->next->size <= i || cur->next->item[i] == C_EMPTY)
		return (true);
	return (false);
}

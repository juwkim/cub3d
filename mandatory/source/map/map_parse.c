/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 04:05:19 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/08 15:27:16 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "camera.h"

static void	map_read(t_map *const map, const int fd);

bool	map_parse(t_map *const map, t_camera *const cam, const int fd)
{
	map_read(map, fd);
	if (map_is_valid(map) == false)
		return (false);
	camera_set(cam, map);
	dlist_print(&map->list);
	return (true);
}

static void	map_read(t_map *const map, const int fd)
{
	char	*line;

	while (true)
	{
		line = ft_get_next_line(fd);
		if (line == NULL)
			break ;
		dlist_push_back(&map->list, line);
	}
}

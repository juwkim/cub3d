/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 04:05:19 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/18 20:12:00 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "camera.h"

static void	map_read(t_map *const map, const int fd);

bool	map_parse(t_cub3d *const cub3d, const int fd)
{
	map_read(&cub3d->map, fd);
	if (map_is_valid(&cub3d->map, &cub3d->tex) == false)
		return (false);
	camera_set(&cub3d->cam, &cub3d->map);
	dlist_print(&cub3d->map.list);
	if (map_list_to_array(cub3d, &cub3d->map) == false)
		return (false);
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

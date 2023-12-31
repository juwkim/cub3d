/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:50:31 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 03:13:45 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

static bool	texture_set(t_texture *const tex, void *mlx, char *line);
static bool	texture_is_valid(const t_texture *const tex);

bool	texture_parse(t_texture *const tex, t_map *const map, void *mlx, \
	const int fd)
{
	char	*line;
	bool	res;

	while (true)
	{
		line = ft_get_next_line(fd);
		if (line == NULL)
		{
			printf("Error\nEOF while parsing texture\n");
			return (false);
		}
		if (ft_strcmp(line, "") != 0)
		{
			if (texture_get_id(line) == T_NONE)
				break ;
			res = texture_set(tex, mlx, line);
		}
		free(line);
		if (res == false)
			return (false);
	}
	if (texture_is_valid(tex) == false)
		return (false);
	dlist_push_back(&map->list, line);
	return (true);
}

static bool	texture_set(t_texture *const tex, void *mlx, char *line)
{
	const enum e_texture	id = texture_get_id(line);

	if (texture_is_bgcolor(id) == true)
		return (texture_set_bgcolor(tex, line + 2, id));
	if (texture_is_wall(id) == true)
		return (texture_set_wall(tex, mlx, line + 3, id));
	if (texture_is_door(id) == true)
		return (texture_set_door(tex, mlx, line + 3, id));
	if (texture_is_sprite(id) == true)
		return (texture_set_sprite(tex, mlx, line + 3, id));
	printf("Error\nUnidentified texture id\n");
	return (false);
}

static bool	texture_is_valid(const t_texture *const tex)
{
	if (tex->img[T_SOUTH].ptr == NULL || \
		tex->img[T_EAST].ptr == NULL || \
		tex->img[T_NORTH].ptr == NULL || \
		tex->img[T_NORTH].ptr == NULL)
	{
		printf("Error\nSome wall texture are omitted\n");
		return (false);
	}
	if (tex->bgcolor[T_FLOOR - N_BGPAD] == 256)
	{
		printf("Error\nFloor color are omitted\n");
		return (false);
	}
	if (tex->bgcolor[T_CEILING - N_BGPAD] == 256)
	{
		printf("Error\nCeiling color are omitted\n");
		return (false);
	}
	return (true);
}

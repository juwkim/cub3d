/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:00:21 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/28 01:04:18 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "cub3d.h"

enum e_mapchar
{
	C_SOUTH = 'S',
	C_EAST = 'E',
	C_NORTH = 'N',
	C_WEST = 'W',
	C_DOOR = 'D',
	C_ITEM = 'I',
	C_SPACE = '0',
	C_WALL = '1',
	C_EMPTY = ' '
};

typedef struct s_map
{
	enum e_texture	**tex_id;
	uint8_t			**off;
	int				width;
	int				height;
}	t_map;

bool	map_init(t_map *const map);
void	map_destroy(const t_map *const map);

#endif // __MAP_H__

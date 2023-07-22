/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:11:49 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/23 01:35:40 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "utils.h"

static void	append(t_map *const map, const char *line);
// static void	check_valid_map(t_map *const map);
// static bool	is_boundary(const int i, const int j, t_map *const map);
// static void	set_player(t_map *const map, t_player *const p);

void	parse_map(t_cub3d *const cub3d, const int fd)
{
	char	*line;

	line = ft_get_next_line(fd);
	while (line && ft_strcmp(line, "") == 0)
	{
		free(line);
		line = ft_get_next_line(fd);
	}
	while (line)
	{
		append(&cub3d->map, line);
		free(line);
		line = ft_get_next_line(fd);
		if (line == NULL)
			break ;
		_assert(ft_strcmp(line, "") != 0, "Empty line in map\n");
	}
	// check_valid_map(&cub3d->map);
	// set_player(&cub3d->map, &cub3d->player);
	cub3d->player.pos.i = 3 * TEX_HEIGHT + TEX_HEIGHT / 2;
	cub3d->player.pos.j = 13 * TEX_WIDTH + TEX_WIDTH / 2;
	cub3d->player.lookat = M_PI;

	int i = 0;
	while (i < cub3d->map.size)
	{
		int j = 0;
		while (cub3d->map.board[i][j])
		{
			if (cub3d->map.board[i][j] != C_EMPTY)
			{
				if (i > 0)
				{
					if (cub3d->map.board[i - 1][j] == C_EMPTY)
						cub3d->map.board[i][j] = C_SOUTH;
					else
						cub3d->map.board[i][j] = C_EAST;
				}
				if (i > 0)
				{
					if (cub3d->map.board[i - 1][j + TEX_WIDTH - 1] == C_EMPTY)
						cub3d->map.board[i][j + TEX_WIDTH - 1] = C_SOUTH;
					else
						cub3d->map.board[i][j + TEX_WIDTH - 1] = C_WEST;
				}
				if (i + TEX_HEIGHT < cub3d->map.size)
				{
					if (cub3d->map.board[i + TEX_HEIGHT][j] == C_EMPTY)
						cub3d->map.board[i + TEX_HEIGHT - 1][j] = C_NORTH;
					else
						cub3d->map.board[i + TEX_HEIGHT - 1][j] = C_EAST;
				}
				if (i + TEX_HEIGHT < cub3d->map.size)
				{
					if (cub3d->map.board[i + TEX_HEIGHT][j + TEX_WIDTH - 1] == C_EMPTY)
						cub3d->map.board[i + TEX_HEIGHT - 1][j + TEX_WIDTH - 1] = C_NORTH;
					else
						cub3d->map.board[i + TEX_HEIGHT - 1][j + TEX_WIDTH - 1] = C_WEST;
				}
			}
			j += TEX_WIDTH;
		}
		i += TEX_HEIGHT;
	}


}

static void	append(t_map *const map, const char *line)
{
	char	**new_board;

	if (map->size == map->capacity)
	{
		map->capacity <<= 1;
		new_board = malloc(sizeof(char *) * map->capacity);
		_assert(new_board != NULL, "append() memory allocation failed\n");
		ft_memcpy(new_board, map->board, sizeof(char *) * map->size);
		free(map->board);
		map->board = new_board;
	}
	int i;
	int j;
	const int len = (int)ft_strlen(line);

	i = 0;
	while (i < TEX_HEIGHT)
	{
		map->board[i + map->size] = malloc(sizeof(char) * (len * TEX_WIDTH + 1));
		_assert(map->board[i + map->size] != NULL, "malloc() failed\n");
		ft_memset(map->board[i + map->size], C_EMPTY, len * TEX_WIDTH);
		map->board[i + map->size][len * TEX_WIDTH] = '\0';
		j = 0;
		if (i == 0)
		{
			while (j < len)
			{
				if (line[j] == '1')
					ft_memset(&map->board[i + map->size][j * TEX_WIDTH], C_SOUTH, TEX_WIDTH);
				++j;
			}
			map->board[i + map->size][len * TEX_WIDTH] = '\0';
		}
		else if (i == TEX_HEIGHT - 1)
		{
			while (j < len)
			{
				if (line[j] == '1')
					ft_memset(&map->board[i + map->size][j * TEX_WIDTH], C_NORTH, TEX_WIDTH);				++j;
			}
		}
		else
		{
			while (j < len)
			{
				if (line[j] == '1')
				{
					map->board[i + map->size][j * TEX_WIDTH] = 'E';
					ft_memset(&map->board[i + map->size][j * TEX_WIDTH + 1], C_FILLED, TEX_WIDTH - 2);
					map->board[i + map->size][(j + 1) * TEX_WIDTH - 1] = 'W';
				}
				++j;
			}
		}
		++i;
	}
	map->size += TEX_HEIGHT;
}

/*
static void	check_valid_map(t_map *const map)
{
	int					i;
	int					j;
	int					player_count;
	int					pos;

	player_count = 0;
	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (map->board[i][j] != '\0')
		{
			pos = _strfind("NSWE01 ", map->board[i][j]);
			_assert(pos < 7, "Map includes not allowed character\n");
			_assert(pos >= 5 || is_boundary(i, j, map) == false,
				"Map boundary includes not wall character\n");
			player_count += (pos <= 3);
			++j;
		}
		++i;
	}
	_assert(player_count == 1, "Player's count is not 1\n");
}

static bool	is_boundary(const int i, const int j, t_map *const map)
{
	_assert(i != 0, "i is zero\n");
	_assert(j != 0, "j is zero\n");
	_assert(i != map->size - 1, "i is map->size - 1\n");
	_assert(map->board[i][j + 1] != '\0', "map->board[i][j + 1] not null ch\n");
	return (
		(ft_strlen(map->board[i - 1]) <= (size_t)j || \
		map->board[i - 1][j] == ' ') || \
		(ft_strlen(map->board[i + 1]) <= (size_t)j || \
		map->board[i + 1][j] == ' ') || \
		map->board[i][j - 1] == ' ' || map->board[i][j + 1] == ' '
	);
}
*/

// void	set_player(t_map *const map, t_player *const p)
// {
// 	int			i;
// 	int			j;
// 	int			off;

// 	i = 0;
// 	while (i < map->size)
// 	{
// 		j = 0;
// 		while (map->board[i][j] != '\0')
// 		{
// 			off = _strfind("SENW", map->board[i][j]);
// 			if (off == 4)
// 			{
// 				++j;
// 				continue ;
// 			}
// 			map->board[i][j] = C_EMPTY;
// 			p->pos.i = i;
// 			p->pos.j = j;
// 			p->lookat = off * M_PI / 2;
// 			return ;
// 		}
// 		++i;
// 	}
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:11:49 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/23 08:36:35 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"
#include "utils_bonus.h"

static void	append(t_map *const map, const char *line);
static void	check_valid_map(t_map *const map);
static bool	is_boundary(const int i, const int j, t_map *const map);
static void	set_player(t_map *const map, t_player *const p);

void	parse_map(t_game *const game, const int fd)
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
		append(&game->map, line);
		line = ft_get_next_line(fd);
		if (line == NULL)
			break ;
		_assert(ft_strcmp(line, "") != 0, "Empty line in map\n");
	}
	check_valid_map(&game->map);
	set_player(&game->map, &game->player);
	map_to_int(&game->map);
	trim_map(game->map.board, game->map.size);
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
	map->board[map->size++] = (char *)line;
}

static void	check_valid_map(t_map *const map)
{
	int	i;
	int	j;
	int	pos;
	int	player_count;

	player_count = 0;
	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (map->board[i][j] != '\0')
		{
			pos = _strfind("SENWD01 ", map->board[i][j]);
			_assert(pos < 8, "Map includes not allowed character\n");
			_assert(pos >= 6 || is_boundary(i, j, map) == false,
				"Map boundary includes not wall character\n");
			player_count += (pos <= 3);
			_assert(player_count <= 1, "Player's count is not 1\n");
			++j;
		}
		++i;
	}
}

static bool	is_boundary(const int i, const int j, t_map *const map)
{
	const char	**board = (const char	**)map->board;

	return (i == 0 || j == 0 || \
		i == map->size - 1 || board[i][j + 1] == '\0' || \
		((int)ft_strlen(board[i - 1]) <= j || board[i - 1][j] == ' ') || \
		((int)ft_strlen(board[i + 1]) <= j || board[i + 1][j] == ' ') || \
		board[i][j - 1] == ' ' || board[i][j + 1] == ' '
	);
}

void	set_player(t_map *const map, t_player *const p)
{
	int			i;
	int			j;
	int			off;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (map->board[i][j] != '\0')
		{
			off = _strfind("SENW", map->board[i][j]);
			if (off == 4)
			{
				++j;
				continue ;
			}
			map->board[i][j] = C_EMPTY;
			p->pos.i = TEX_HEIGHT * i + TEX_HEIGHT / 2;
			p->pos.j = TEX_WIDTH * j + TEX_WIDTH / 2;
			p->lookat = off * M_PI_2;
			return ;
		}
		++i;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 03:31:34 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 18:08:04 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "utils.h"

static void	init_board(char **const board, char *line);
static void	fill_wall(char **const new, const int i, const int j);

void	set_map(char **const map, const int map_size, t_map *const rmap)
{
	int				i;
	int				j;
	char **const	new = malloc(sizeof(char *) * map->size * TEX_HEIGHT);

	_assert(new != NULL, "malloc() failed\n");
	i = 0;
	while (i < map->size)
	{
		init_board(&new[TEX_HEIGHT * i], map->board[i]);
		j = 0;
		while (map->board[i][j] != '\0')
		{
			if (map->board[i][j] == C_FILLED)
				fill_wall(new, i, j);
			++j;
		}
		free(map->board[i]);
		++i;
	}
	free(map->board);
	map->board = new;
	map->size *= TEX_HEIGHT;
}

static void	init_board(char **const board, char *line)
{
	const int	len = (int)ft_strlen(line);
	int			i;

	i = 0;
	while (i < TEX_HEIGHT)
	{
		board[i] = malloc(sizeof(char) * len * TEX_WIDTH + 1);
		_assert(board[i] != NULL, "malloc() failed\n");
		ft_memset(board[i], C_EMPTY, len * TEX_WIDTH);
		board[i][len * TEX_WIDTH] = '\0';
		++i;
	}
}

static void	fill_wall(char **const new, const int i, const int j)
{
	int	k;

	ft_memset(&new[TEX_HEIGHT * i][TEX_WIDTH * j], C_SOUTH, TEX_WIDTH);
	k = TEX_HEIGHT * i + 1;
	while (k < TEX_HEIGHT * (i + 1) - 1)
	{
		new[k][TEX_WIDTH * j] = C_EAST;
		ft_memset(&new[k][TEX_WIDTH * j + 1], \
			C_FILLED, TEX_WIDTH - 2);
		new[k][TEX_WIDTH * (j + 1) - 1] = C_WEST;
		++k;
	}
	ft_memset(&new[TEX_HEIGHT * (i + 1) - 1][TEX_WIDTH * j], \
		C_NORTH, TEX_WIDTH);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 03:31:34 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/23 04:52:21 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "utils.h"

void	map_to_int(t_map *const map)
{
	int				i;
	int				j;
	int				k;
	int				p;
	int				len;
	char **const	new_board = malloc(sizeof(char *) * map->size * TEX_HEIGHT);

	_assert(new_board != NULL, "malloc() failed\n");
	i = 0;
	while (i < map->size)
	{
		len = (int)ft_strlen(map->board[i]);
		p = TEX_HEIGHT * i;
		while (p < TEX_HEIGHT * (i + 1))
		{
			new_board[p] = malloc(sizeof(char) * len * TEX_WIDTH + 1);
			_assert(new_board[p] != NULL, "malloc() failed\n");
			ft_memset(new_board[p], C_EMPTY, len * TEX_WIDTH);
			new_board[p][len * TEX_WIDTH] = '\0';
			++p;
		}
		j = 0;
		while (j < len)
		{
			if (map->board[i][j] == C_FILLED)
			{
				ft_memset(&new_board[TEX_HEIGHT * i][TEX_WIDTH * j], \
					C_SOUTH, TEX_WIDTH);
				k = TEX_HEIGHT * i + 1;
				while (k < TEX_HEIGHT * (i + 1) - 1)
				{
					new_board[k][TEX_WIDTH * j] = C_EAST;
					ft_memset(&new_board[k][TEX_WIDTH * j + 1], \
						C_FILLED, TEX_WIDTH - 2);
					new_board[k][TEX_WIDTH * (j + 1) - 1] = C_WEST;
					++k;
				}
				ft_memset(&new_board[TEX_HEIGHT * (i + 1) - 1][TEX_WIDTH * j], \
					C_NORTH, TEX_WIDTH);
			}
			++j;
		}
		free(map->board[i]);
		++i;
	}
	free(map->board);
	map->board = new_board;
	map->size *= TEX_HEIGHT;
}

void	trim_map(char **const board, const int map_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_size)
	{
		j = 0;
		while (board[i][j] != '\0')
		{
			if (board[i][j] != C_EMPTY)
			{
				if (i > 0)
				{
					if (board[i - 1][j] == C_EMPTY)
					{
						board[i][j] = C_SOUTH;
						board[i][j + TEX_WIDTH - 1] = C_SOUTH;
					}
					else
					{
						board[i][j] = C_EAST;
						board[i][j + TEX_WIDTH - 1] = C_WEST;
					}
				}
				if (i + TEX_HEIGHT < map_size)
				{
					if (board[i + TEX_HEIGHT][j] == C_EMPTY)
					{
						board[i + TEX_HEIGHT - 1][j] = C_NORTH;
						board[i + TEX_HEIGHT - 1][j + TEX_WIDTH - 1] = C_NORTH;
					}
					else
					{
						board[i + TEX_HEIGHT - 1][j] = C_EAST;
						board[i + TEX_HEIGHT - 1][j + TEX_WIDTH - 1] = C_WEST;
					}
				}
			}
			j += TEX_WIDTH;
		}
		i += TEX_HEIGHT;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 05:48:13 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/23 06:07:06 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	trim_upper(char **const board, const int i, const int j);
static void	trim_lower(char **const board, const int i, const int j);

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
					trim_upper(board, i, j);
				if (i + TEX_HEIGHT < map_size)
					trim_lower(board, i, j);
			}
			j += TEX_WIDTH;
		}
		i += TEX_HEIGHT;
	}
}

static void	trim_upper(char **const board, const int i, const int j)
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

static void	trim_lower(char **const board, const int i, const int j)
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

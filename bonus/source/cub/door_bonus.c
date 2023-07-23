/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 09:00:33 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/23 09:29:15 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"
#include "utils_bonus.h"

void	fill_door(char **const new, const char **board, \
	const int i, const int j)
{
	int	k;

	if (board[i][j - 1] == C_WALL && board[i][j + 1] == C_WALL && \
		board[i - 1][j] == C_EMPTY && board[i + 1][j] == C_EMPTY)
	{
		ft_memset(&new[TEX_HEIGHT * i][TEX_WIDTH * j], \
			C_DOOR_HORIZONTAL, TEX_WIDTH);
		ft_memset(&new[TEX_HEIGHT * (i + 1) - 1][TEX_WIDTH * j], \
			C_DOOR_HORIZONTAL, TEX_WIDTH);
	}
	else if (board[i][j - 1] == C_EMPTY && board[i][j + 1] == C_EMPTY && \
		board[i - 1][j] == C_WALL && board[i + 1][j] == C_WALL)
	{
		k = 0;
		while (k < TEX_HEIGHT)
		{
			new[TEX_HEIGHT * i + k][TEX_WIDTH * j + TEX_WIDTH / 2] = \
				C_DOOR_VERTICAL;
			++k;
		}
	}
	else
		_assert(false, "Door located in invalid position\n");
}

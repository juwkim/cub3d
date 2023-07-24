/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:44:35 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 12:01:32 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	set_image_and_off(t_config *const config, t_texture *tex, \
	const int i, const int j);

void	raycasting(t_config *const config, double lookat, t_texture *tex)
{
	double			move_i;
	double			move_j;
	double			dist;
	const double	c = LR * cos(lookat);
	const double	s = LR * sin(lookat);

	move_i = 0.0f;
	move_j = 0.0f;
	while (true)
	{
		move_i += c;
		move_j += s;
		if (config->map.board[(int)(config->player.pos.i + move_i)] \
			[(int)(config->player.pos.j + move_j)] != C_EMPTY)
			break ;
	}
	dist = sqrt(move_i * move_i + move_j * move_j) * \
		cos(lookat - config->player.lookat) / TEX_WIDTH;
	tex->start = (int)(0.5 * WIN_HEIGHT - 0.5 * WIN_HEIGHT / dist);
	tex->end = (int)(0.5 * WIN_HEIGHT + 0.5 * WIN_HEIGHT / dist);
	set_image_and_off(config, tex, \
	(int)(config->player.pos.i + move_i), (int)(config->player.pos.j + move_j));
}

static void	set_image_and_off(t_config *const config, t_texture *tex, \
	const int i, const int j)
{
	if (config->map.board[i][j] == C_NORTH)
	{
		tex->img = &config->img[NORTH];
		tex->off = j % TEX_WIDTH;
	}
	else if (config->map.board[i][j] == C_WEST)
	{
		tex->img = &config->img[WEST];
		tex->off = (TEX_HEIGHT - 1) - i % TEX_HEIGHT;
	}
	else if (config->map.board[i][j] == C_SOUTH)
	{
		tex->img = &config->img[SOUTH];
		tex->off = (TEX_WIDTH - 1) - j % TEX_WIDTH;
	}
	else if (config->map.board[i][j] == C_EAST)
	{
		tex->img = &config->img[EAST];
		tex->off = i % TEX_HEIGHT;
	}
}

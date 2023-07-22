/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:44:35 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/23 01:35:40 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	set_image_and_off(t_cub3d *const cub3d, t_texture *tex, \
	const int i, const int j);

void	raycasting(t_cub3d *const cub3d, double lookat, t_texture *tex)
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
		if (cub3d->map.board[(int)(cub3d->player.pos.i + move_i)] \
			[(int)(cub3d->player.pos.j + move_j)] != C_EMPTY)
			break ;
	}
	dist = sqrt(move_i * move_i + move_j * move_j) * \
		cos(lookat - cub3d->player.lookat) / TEX_WIDTH;
	tex->start = (int)(0.5 * WIN_HEIGHT - 0.5 * WIN_HEIGHT / dist);
	tex->end = (int)(0.5 * WIN_HEIGHT + 0.5 * WIN_HEIGHT / dist);
	set_image_and_off(cub3d, tex, \
	(int)(cub3d->player.pos.i + move_i), (int)(cub3d->player.pos.j + move_j));
}

static void	set_image_and_off(t_cub3d *const cub3d, t_texture *tex, \
	const int i, const int j)
{
	if (cub3d->map.board[i][j] == C_NORTH)
	{
		tex->img = &cub3d->img[NORTH];
		tex->off = j % TEX_WIDTH;
	}
	else if (cub3d->map.board[i][j] == C_WEST)
	{
		tex->img = &cub3d->img[WEST];
		tex->off = (TEX_HEIGHT - 1) - i % TEX_HEIGHT;
	}
	else if (cub3d->map.board[i][j] == C_SOUTH)
	{
		tex->img = &cub3d->img[SOUTH];
		tex->off = (TEX_WIDTH - 1) - j % TEX_WIDTH;
	}
	else if (cub3d->map.board[i][j] == C_EAST)
	{
		tex->img = &cub3d->img[EAST];
		tex->off = i % TEX_HEIGHT;
	}
}

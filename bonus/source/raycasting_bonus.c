/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:44:35 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/23 09:21:35 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

static void	set_image(t_game *const game, t_texture *tex, \
	const int i, const int j);
static void	set_off(t_game *const game, t_texture *tex, \
	const int i, const int j);

void	raycasting(t_game *const game, double lookat, t_texture *tex)
{
	double			di;
	double			dj;
	double			dist;
	const double	c = LR * cos(lookat);
	const double	s = LR * sin(lookat);

	di = 0.0f;
	dj = 0.0f;
	while (true)
	{
		di += c;
		dj += s;
		if (game->map.board[(int)(game->player.pos.i + di)] \
			[(int)(game->player.pos.j + dj)] != C_EMPTY)
			break ;
	}
	dist = sqrt(di * di + dj * dj) * \
		cos(lookat - game->player.lookat) / TEX_WIDTH;
	tex->start = (int)(0.5 * WIN_HEIGHT - 0.5 * WIN_HEIGHT / dist);
	tex->end = (int)(0.5 * WIN_HEIGHT + 0.5 * WIN_HEIGHT / dist);
	set_image(game, tex, game->player.pos.i + di, game->player.pos.j + dj);
	set_off(game, tex, game->player.pos.i + di, game->player.pos.j + dj);
}

static void	set_image(t_game *const game, t_texture *tex, \
	const int i, const int j)
{
	if (game->map.board[i][j] == C_NORTH)
		tex->img = &game->img[NORTH];
	else if (game->map.board[i][j] == C_WEST)
		tex->img = &game->img[WEST];
	else if (game->map.board[i][j] == C_SOUTH)
		tex->img = &game->img[SOUTH];
	else if (game->map.board[i][j] == C_EAST)
		tex->img = &game->img[EAST];
	else if (game->map.board[i][j] == C_DOOR_HORIZONTAL)
		tex->img = &game->img[DOOR];
	else if (game->map.board[i][j] == C_DOOR_VERTICAL)
		tex->img = &game->img[DOOR];
}

static void	set_off(t_game *const game, t_texture *tex, \
	const int i, const int j)
{
	if (game->map.board[i][j] == C_NORTH)
		tex->off = j % TEX_WIDTH;
	else if (game->map.board[i][j] == C_WEST)
		tex->off = (TEX_HEIGHT - 1) - i % TEX_HEIGHT;
	else if (game->map.board[i][j] == C_SOUTH)
		tex->off = (TEX_WIDTH - 1) - j % TEX_WIDTH;
	else if (game->map.board[i][j] == C_EAST)
		tex->off = i % TEX_HEIGHT;
	else if (game->map.board[i][j] == C_DOOR_HORIZONTAL)
		tex->off = j % TEX_HEIGHT;
	else if (game->map.board[i][j] == C_DOOR_VERTICAL)
		tex->off = i % TEX_WIDTH;
}

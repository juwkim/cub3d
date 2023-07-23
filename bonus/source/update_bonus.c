/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:19:54 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/23 08:08:36 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update_bonus.h"
#include "event_bonus.h"

static bool		rotate(t_game *const game, const int rotation, \
	double *const lookat);
static bool		move(const t_key *const key, const char *const *const board, \
	t_player *const p);
static double	get_moving_direction(const t_key *const key, double lookat);

bool	update(t_game *const game, const t_key *const key)
{
	bool	rotated;
	bool	moved;

	if (key->esc == true)
		destroy(game);
	rotated = rotate(game, key->rotation, &game->player.lookat);
	moved = move(key, (const char *const *const)game->map.board, \
		&game->player);
	return (rotated | moved);
}

static bool	rotate(t_game *const game, const int rotation, double *const lookat)
{
	int		x;
	int		y;
	bool	rotated;

	rotated = false;
	mlx_mouse_get_pos(game->win, &x, &y);
	if (0 <= y && y < WIN_HEIGHT && ((0 <= x && x < WIN_WIDTH / 3) || \
		(WIN_WIDTH * 2 / 3 <= x && x < WIN_WIDTH)))
	{
		*lookat += (WIN_WIDTH / 2 - x) * RT_SPEED / WIN_HEIGHT;
		rotated = true;
	}
	if (rotation != KEY_RELESED)
	{
		if (rotation == KEY_LEFT)
			*lookat += RT_SPEED;
		else if (rotation == KEY_RIGHT)
			*lookat -= RT_SPEED;
		if (*lookat >= 2 * M_PI)
			*lookat -= 2 * M_PI;
		else if (*lookat < 0)
			*lookat += 2 * M_PI;
		rotated = true;
	}
	return (rotated);
}

static bool	move(const t_key *const key, const char *const *const board, \
	t_player *const p)
{
	double	direction;
	int		di;
	int		dj;
	bool	moved;

	if (key->vertical == KEY_RELESED && key->horizontal == KEY_RELESED)
		return (false);
	direction = get_moving_direction(key, p->lookat);
	di = round(cos(direction) * MV_SPEED);
	if ((di >= 0 && board[p->pos.i + di + MARGIN][p->pos.j] == C_EMPTY) || \
		(di < 0 && board[p->pos.i + di - MARGIN][p->pos.j] == C_EMPTY))
	{
		p->pos.i += di;
		moved = true;
	}
	dj = round(sin(direction) * MV_SPEED);
	if ((dj >= 0 && board[p->pos.i][p->pos.j + dj + MARGIN] == C_EMPTY) || \
		(dj < 0 && board[p->pos.i][p->pos.j + dj - MARGIN] == C_EMPTY))
	{
		p->pos.j += dj;
		moved = true;
	}
	return (moved);
}

static double	get_moving_direction(const t_key *const key, double lookat)
{
	double	direction;

	direction = lookat;
	if (key->vertical == KEY_W && key->horizontal == KEY_A)
		direction += M_PI_4;
	else if (key->vertical == KEY_S && key->horizontal == KEY_A)
		direction += M_PI_2 + M_PI_4;
	else if (key->vertical == KEY_S && key->horizontal == KEY_D)
		direction += M_PI + M_PI_4;
	else if (key->vertical == KEY_W && key->horizontal == KEY_D)
		direction += M_PI + M_PI_2 + M_PI_4;
	else if (key->vertical == KEY_W)
		direction += 0.0f;
	else if (key->horizontal == KEY_A)
		direction += M_PI_2;
	else if (key->vertical == KEY_S)
		direction += M_PI;
	else if (key->horizontal == KEY_D)
		direction += M_PI + M_PI_2;
	return (direction);
}

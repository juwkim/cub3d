/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:19:54 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 12:01:32 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"
#include "event.h"

static bool		rotate(const int rotation, double *const lookat);
static bool		move(const t_key *const key, const char *const *const board, \
	t_player *const p);
static double	get_moving_direction(const t_key *const key, double lookat);

bool	update(t_config *const config, const t_key *const key)
{
	bool	rotated;
	bool	moved;

	if (key->esc == true)
		destroy(config);
	rotated = rotate(key->rotation, &config->player.lookat);
	moved = move(key, (const char *const *const)config->map.board, \
		&config->player);
	return (rotated | moved);
}

static bool	rotate(const int rotation, double *const lookat)
{
	if (rotation == KEY_RELESED)
		return (false);
	if (rotation == KEY_LEFT)
		*lookat += RT_SPEED;
	else if (rotation == KEY_RIGHT)
		*lookat -= RT_SPEED;
	if (*lookat >= 2 * M_PI)
		*lookat -= 2 * M_PI;
	else if (*lookat < 0)
		*lookat += 2 * M_PI;
	return (true);
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

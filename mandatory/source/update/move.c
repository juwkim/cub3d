/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:10:31 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 03:46:41 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"
#include "key.h"

static double	get_moving_direction(const t_key *const key, \
	const double lookat);
static bool		is_vertical_movable(t_camera *const cam, \
	t_pixel **const data, const int di);
static bool		is_horizontal_movable(t_camera *const cam, \
	t_pixel **const data, const int dj);

bool	move(const t_key *const key, t_camera *const cam, t_pixel **const data)
{
	double	direction;
	bool	moved;
	int		di;
	int		dj;

	if (key->vertical == KEY_RELESE && key->horizontal == KEY_RELESE)
		return (false);
	moved = false;
	direction = get_moving_direction(key, cam->lookat);
	di = round(cos(direction) * MV_SPEED);
	dj = round(sin(direction) * MV_SPEED);
	if (is_vertical_movable(cam, data, di) == true)
	{
		cam->pos.i += di;
		moved = true;
	}
	if (is_horizontal_movable(cam, data, dj) == true)
	{
		cam->pos.j += dj;
		moved = true;
	}
	return (moved);
}

static double	get_moving_direction(const t_key *const key, \
	const double lookat)
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

static bool	is_vertical_movable(t_camera *const cam, t_pixel **const data, \
	const int di)
{
	int	s;
	int	e;

	if (di == 0)
		return (false);
	if (di > 0)
	{
		s = cam->pos.i;
		e = cam->pos.i + di + MARGIN;
	}
	else
	{
		s = cam->pos.i + di - MARGIN;
		e = cam->pos.i;
	}
	while (s <= e)
	{
		if (data[s][cam->pos.j].tex_id != SPACE)
			return (false);
		++s;
	}
	return (true);
}

static bool	is_horizontal_movable(t_camera *const cam, t_pixel **const data, \
	const int dj)
{
	int	s;
	int	e;

	if (dj == 0)
		return (false);
	if (dj > 0)
	{
		s = cam->pos.j;
		e = cam->pos.j + dj + MARGIN;
	}
	else
	{
		s = cam->pos.j + dj - MARGIN;
		e = cam->pos.j;
	}
	while (s <= e)
	{
		if (data[cam->pos.i][s].tex_id != SPACE)
			return (false);
		++s;
	}
	return (true);
}

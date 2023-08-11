/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move_by_key.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:10:31 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/11 23:44:49 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

static void		camera_get_moving_distance(t_camera *const cam, \
	const t_key *const key, double *const di, double *const dj);
static double	camera_get_moving_direction(const t_camera *const cam, \
	const t_key *const key);
static bool		camera_move_to_i(t_camera *const cam, const t_map *const map, \
	const t_texture *const tex, const double di);
static bool		camera_move_to_j(t_camera *const cam, const t_map *const map, \
	const t_texture *const tex, const double dj);

bool	camera_move_by_key(t_camera *const cam, const t_key *const key, \
	const t_map *const map, const t_texture *const tex)
{
	double	di;
	double	dj;
	bool	i_moved;
	bool	j_moved;

	if (key->vertical == KEY_RELESE && key->horizontal == KEY_RELESE)
		return (false);
	camera_get_moving_distance(cam, key, &di, &dj);
	i_moved = camera_move_to_i(cam, map, tex, di);
	j_moved = camera_move_to_j(cam, map, tex, dj);
	return (i_moved | j_moved);
}

static void	camera_get_moving_distance(t_camera *const cam, \
	const t_key *const key, double *const di, double *const dj)
{
	const double	moving_direction = camera_get_moving_direction(cam, key);

	*di = cos(moving_direction) * key->moving_speed;
	*dj = sin(moving_direction) * key->moving_speed;
}

static double	camera_get_moving_direction(const t_camera *const cam, \
	const t_key *const key)
{
	double	direction;

	direction = cam->angle;
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

static bool	camera_move_to_i(t_camera *const cam, const t_map *const map, \
	const t_texture *const tex, const double di)
{
	int	s;
	int	e;

	if (di == 0.0f)
		return (false);
	if (di > 0.0f)
	{
		s = (int)round(cam->i);
		e = (int)round(cam->i + di + tex->barrior_dist);
	}
	else
	{
		s = (int)round(cam->i + di - tex->barrior_dist);
		e = (int)round(cam->i);
	}
	while (s <= e)
	{
		if (map->tex_id[s][(int)round(cam->j)] != T_SPACE)
			return (false);
		++s;
	}
	cam->i += di;
	return (true);
}

static bool	camera_move_to_j(t_camera *const cam, const t_map *const map, \
	const t_texture *const tex, const double dj)
{
	int	s;
	int	e;

	if (dj == 0.0f)
		return (false);
	if (dj > 0.0f)
	{
		s = (int)round(cam->j);
		e = (int)round(cam->j + dj + tex->barrior_dist);
	}
	else
	{
		s = (int)round(cam->j + dj - tex->barrior_dist);
		e = (int)round(cam->j);
	}
	while (s <= e)
	{
		if (map->tex_id[(int)round(cam->i)][s] != T_SPACE)
			return (false);
		++s;
	}
	cam->j += dj;
	return (true);
}

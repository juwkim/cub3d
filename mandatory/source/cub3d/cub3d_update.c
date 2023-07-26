/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:19:54 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 04:19:18 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "update.h"
#include "key.h"

bool	cub3d_update(t_cub3d *const cub3d)
{
	bool	rotated;
	bool	moved;
	t_key	*key;

	key = &cub3d->key;
	if (key->esc == true)
		cub3d_destroy(cub3d);
	rotated = rotate(cub3d, key->rotation, &cub3d->cam.lookat);
	moved = move(key, &cub3d->cam, cub3d->map.data);
	return (rotated | moved);
}

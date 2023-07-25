/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:19:54 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/25 02:56:10 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"
#include "key.h"

bool	update(t_config *const config, const t_key *const key)
{
	bool	rotated;
	bool	moved;

	if (key->esc == true)
		destroy(config);
	rotated = rotate(config, key->rotation, &config->cam.lookat);
	moved = move(key, &config->cam, config->map.data);
	return (rotated | moved);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 03:11:17 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 03:20:23 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub3d_play(t_cub3d *const cub3d)
{
	static bool	updated = true;

	if (updated)
		cub3d_render(cub3d);
	updated = cub3d_update(cub3d);
	return (0);
}

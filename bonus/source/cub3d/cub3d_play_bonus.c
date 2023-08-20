/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 03:11:17 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:39:54 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	cub3d_play(t_cub3d *const cub3d)
{
	static bool	updated = true;

	if (updated)
		cub3d_render(cub3d);
	updated = cub3d_update(cub3d);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_fill_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:17:54 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:44:10 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wall_bonus.h"

void	wall_fill_map(t_cub3d *const cub3d, int i, int j)
{
	wall_fill_map_south(cub3d, i, j);
	wall_fill_map_east(cub3d, i, j);
	wall_fill_map_north(cub3d, i + TEX_HEIGHT - 1, j);
	wall_fill_map_west(cub3d, i, j + TEX_WIDTH - 1);
}

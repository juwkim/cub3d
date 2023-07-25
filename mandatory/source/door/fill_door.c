/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:05:59 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/25 16:00:49 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door.h"
#include "cub.h"

void	fill_door(t_pixel *const *const data, const int i, const int j)
{
	fill_south(data, i, j, DOOR);
	fill_east(data, i, j, DOOR);
	fill_north(data, i + TEX_HEIGHT - 1, j, DOOR);
	fill_west(data, i, j + TEX_WIDTH - 1, DOOR);
}

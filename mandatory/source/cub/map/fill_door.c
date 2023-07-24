/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:05:59 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 19:16:46 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fill_door(t_pixel **const data, int i, int j)
{
	fill_south(data, i, j, DOOR);
	fill_east(data, i, j, DOOR);
	fill_north(data, i + TEX_HEIGHT - 1, j, DOOR);
	fill_west(data, i, j + TEX_WIDTH - 1, DOOR);
}

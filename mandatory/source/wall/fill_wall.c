/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:48:35 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/25 16:03:24 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fill_wall(t_pixel *const *const data, const int i, const int j)
{
	fill_south(data, i, j, SOUTH);
	fill_east(data, i, j, EAST);
	fill_north(data, i + TEX_HEIGHT - 1, j, NORTH);
	fill_west(data, i, j + TEX_WIDTH - 1, WEST);
}

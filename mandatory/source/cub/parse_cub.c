/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 05:14:08 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 02:48:50 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "utils.h"

void	parse_cub(t_cub3d *const cub3d, const char *filename)
{
	int	fd;

	_assert(is_extension(filename, ".cub") == true, "Usage: .cub3D *.cub\n");
	fd = open(filename, O_RDONLY);
	_assert(fd != -1, strerror(errno));
	parse_texture_sprite_color(cub3d, fd);
	parse_map(cub3d, fd);
}

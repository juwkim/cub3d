/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 05:14:08 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 15:16:06 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "utils.h"

void	parse_cub(t_config *const config, const char *filename)
{
	int	fd;

	_assert(is_extension(filename, ".cub") == true, "Usage: .cub3D *.cub\n");
	fd = open(filename, O_RDONLY);
	_assert(fd != -1, strerror(errno));
	parse_texture_and_color(config, fd);
	parse_map(config, fd);
}

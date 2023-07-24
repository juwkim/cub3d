/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 05:14:08 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 14:32:04 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "utils.h"

void	parse_cub(t_config *const config, const char *cub_file)
{
	int	fd;

	_assert(is_extension(cub_file, ".cub") == true, "Usage: .cub3D *.cub\n");
	fd = open(cub_file, O_RDONLY);
	_assert(fd != -1, strerror(errno));
	parse_texture(config, fd);
	parse_map(config, fd);
}

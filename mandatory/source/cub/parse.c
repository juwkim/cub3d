/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 05:14:08 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 12:08:13 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "utils.h"

void	parse_cub(t_config *const config, const char *cub_file)
{
	const int	fd = open(cub_file, O_RDONLY);

	_assert(fd != -1, strerror(errno));
	_assert(is_extension(cub_file, ".cub") == true, "Usage: .cub3D *.cub\n");
	parse_texture(config, fd);
	parse_map(config, fd);
}

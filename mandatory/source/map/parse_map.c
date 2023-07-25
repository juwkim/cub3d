/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:11:49 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 19:19:21 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	parse_map(t_config *const config, const int fd)
{
	int				map_size;
	char **const	map = read_map(fd, &map_size);

	traverse_map(map, map_size, &config->cam);
	set_map(map, map_size, &config->map);
	trim_map(&config->map);
}

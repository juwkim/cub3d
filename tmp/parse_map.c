/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:11:49 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/28 01:20:52 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	parse_map(t_cub3d *const cub3d, const int fd)
{
	int				map_size;
	char **const	map = read_map(fd, &map_size);

	traverse_map(map, map_size, &cub3d->cam);
	set_map(map, map_size, &cub3d->map);
	trim_map(&cub3d->map);
}

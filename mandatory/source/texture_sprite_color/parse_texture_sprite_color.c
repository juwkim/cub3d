/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_sprite_color.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 06:16:22 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 02:48:50 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "utils.h"

void	parse_texture_sprite_color(t_cub3d *const cub3d, const int fd)
{
	char			*line;
	int				count;
	enum e_texture	tex_id;
	enum e_color	color_id;

	count = 0;
	while (count < TEXTURE_COUNT + COLOR_COUNT)
	{
		line = ft_get_next_line(fd);
		_assert(line != NULL, "EOF before enough texture parsed\n");
		if (ft_strlen(line) > 0)
		{
			if (is_texture(line, &tex_id) == true)
				set_texture(&cub3d->tex[tex_id], cub3d->mlx, line + 3);
			else if (is_sprite(line, &tex_id) == true)
				set_texture(&cub3d->tex[tex_id], cub3d->mlx, line + 3);
			else if (is_color(line, &color_id) == true)
				set_color(&cub3d->color[color_id], line + 2);
			else
				_assert(false, "Invalid texture or color is included\n");
			count += (is_sprite(line, &tex_id) == false);
		}
		free(line);
	}
}

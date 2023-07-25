/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_sprite_color.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 06:16:22 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/25 02:39:02 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "utils.h"

void	parse_texture_sprite_color(t_config *const config, const int fd)
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
				set_texture(&config->tex[tex_id], config->mlx, line + 3);
			else if (is_sprite(line, &tex_id) == true)
				set_texture(&config->tex[tex_id], config->mlx, line + 3);
			else if (is_color(line, &color_id) == true)
				set_color(&config->color[color_id], line + 2);
			else
				_assert(false, "Invalid texture or color is included\n");
			count += (is_sprite(line, &tex_id) == false);
		}
		free(line);
	}
}

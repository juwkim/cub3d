/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 06:16:22 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/28 01:21:18 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

bool	texture_parse(t_cub3d *const cub3d, t_texture *const tex, const int fd)
{
	char	*line;

	while (true)
	{
		line = ft_get_next_line(fd);
		if (line == NULL)
		{
			printf("Error\nEOF while parsing texture\n");
			return (false);
		}
		if (ft_strcmp(line, "") == 0)
		{
			free(line);
			continue ;
		}
		
		free(line);
	}
}

bool	set_texture(t_cub3d *const cub3d, t_texture *const texture, \
	const char *line)
{
	if (is_wall(line) || is_door(line) || is_sprite(line))
		set_texture(&cub3d->tex[tex_id], cub3d->mlx, line + 3);
	else if (is_color(line, &color_id) == true)
		set_color(&cub3d->color[color_id], line + 2);
	else
		_assert(false, "Invalid texture or color is included\n");
}

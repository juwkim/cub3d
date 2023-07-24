/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:46:58 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 15:51:13 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "utils.h"

bool	is_texture(const char *line, enum e_texture *out_tex_id)
{
	if (ft_strncmp(line, "SO ", ft_strlen("SO ")) == 0)
	{
		*out_tex_id = SOUTH;
		return (true);
	}
	if (ft_strncmp(line, "EA ", ft_strlen("EA ")) == 0)
	{
		*out_tex_id = EAST;
		return (true);
	}
	if (ft_strncmp(line, "NO ", ft_strlen("NO ")) == 0)
	{
		*out_tex_id = NORTH;
		return (true);
	}
	if (ft_strncmp(line, "WE ", ft_strlen("WE ")) == 0)
	{
		*out_tex_id = WEST;
		return (true);
	}
	return (false);
}

void	set_texture(t_img *const tex, void *mlx, const char *filename)
{
	_assert(is_extension(filename, ".xpm") == true, "image is not xpm file\n");
	_assert(tex->img == NULL, "Duplicated image\n");
	tex->img = mlx_xpm_file_to_image(mlx, (char *)filename, \
		&tex->width, &tex->height);
	_assert(tex->img != NULL, "mlx_xpm_file_to_image() failed\n");
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->len, &tex->endian);
	_assert(tex->addr != NULL, "mlx_get_data_addr() failed\n");
}

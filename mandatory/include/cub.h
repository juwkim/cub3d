/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:16:19 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 18:08:09 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "config.h"

# define DEFAULT_MAP_CAPACITY	1024

// parse.c
void	parse_cub(t_config *const config, const char *filename);

// parse_texture_and_color.c
void	parse_texture_and_color(t_config *const config, const int fd);

// texture.c
bool	is_texture(const char *line, enum e_texture *out_tex_id);
void	set_texture(t_img *const tex, void *mlx, const char *filename);

// color.c
bool	is_color(const char *line, enum e_color *out_color_id);
void	set_color(t_color *const color, const char *line);

// parse_map.c
void	parse_map(t_config *const config, const int fd);

// read_map.c
char	**read_map(const int fd, int *out_map_size);

// traverse_map.c
void	traverse_map(char **const map, const int map_size, t_camera *const cam);

// set_camera.c
void	set_camera(t_camera *const cam, char **const map, \
	const int i, const int j);

// set_map.c
void	set_map(char **const map, const int map_size, t_map *const rmap);

#endif // __CUB_H__

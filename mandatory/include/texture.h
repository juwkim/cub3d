/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:07:13 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 01:53:48 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "cub3d.h"
# include "image.h"

bool			texture_init(t_texture *const tex, const int barrior_dist);
void			texture_destroy(t_texture *const tex, void *mlx);

enum e_texture	texture_get_id(const char *str);

bool			texture_is_wall(const enum e_texture id);
bool			texture_is_door(const enum e_texture id);
bool			texture_is_sprite(const enum e_texture id);
bool			texture_is_bgcolor(const enum e_texture id);

void			texture_render(t_cub3d *const cub3d);
void			texture_render_background(const t_texture *const tex, \
	t_window *const win);

bool			texture_parse(t_texture *const tex, t_map *const map, \
	void *mlx, const int fd);
bool			texture_set_bgcolor(t_texture *const tex, const char *line, \
	const enum e_texture id);
bool			texture_set_wall(t_texture *const tex, void *mlx, \
	char *filename, const enum e_texture id);
bool			texture_set_door(t_texture *const tex, void *mlx, \
	char *filename, const enum e_texture id);
bool			texture_set_sprite(t_texture *const tex, void *mlx, \
	char *filename, const enum e_texture id);

#endif // __TEXTURE_H__

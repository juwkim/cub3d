/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:07:13 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/31 07:37:56 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "cub3d.h"

enum e_texture
{
	T_SOUTH,
	T_EAST,
	T_NORTH,
	T_WEST,
	T_DOOR,
	T_SPRITE,
	T_FLOOR,
	T_CEILING,
	T_SPACE,
	T_NONE
};

bool			texture_init(t_texture *const tex, const int barrior_dist);
void			texture_destroy(const t_texture *const tex, void *mlx);

enum e_texture	texture_get_id(const char *str);

bool			texture_is_wall(const enum e_texture id);
bool			texture_is_door(const enum e_texture id);
bool			texture_is_sprite(const enum e_texture id);
bool			texture_is_bgcolor(const enum e_texture id);

#endif // __TEXTURE_H__

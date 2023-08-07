/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_set_door.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:36:11 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/08 00:05:44 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

bool	texture_set_door(t_texture *const tex, void *mlx, char *filename, \
	const enum e_texture id)
{
	if (image_init_by_xpm_file(&tex->img[id], mlx, filename) == false)
		return (false);
	return (true);
}

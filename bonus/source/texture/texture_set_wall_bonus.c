/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_set_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:36:11 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:43:46 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_bonus.h"

bool	texture_set_wall(t_texture *const tex, void *mlx, char *filename, \
	const enum e_texture id)
{
	if (image_init_by_xpm_file(&tex->img[id], mlx, filename) == false)
		return (false);
	return (true);
}

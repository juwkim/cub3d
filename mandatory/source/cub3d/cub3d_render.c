/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 04:44:24 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/07 02:25:04 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "texture.h"

void	cub3d_render(t_cub3d *const cub3d)
{
	t_window *const	win = cub3d->win;

	texture_render(cub3d->tex, cub3d->win);
	mlx_put_image_to_window(cub3d->mlx, win->ptr, win->img, 0, 0);
}

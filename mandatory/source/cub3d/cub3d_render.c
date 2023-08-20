/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 04:44:24 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 15:45:21 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "window.h"
#include "texture.h"

void	cub3d_render(t_cub3d *const cub3d)
{
	t_window *const		win = &cub3d->win;
	t_minimap *const	minimap = &cub3d->minimap;

	window_render_background(win);
	texture_render(cub3d);
	texture_render_sprite(cub3d);
	mlx_put_image_to_window(cub3d->mlx, win->ptr, win->img.ptr, 0, 0);
	mlx_put_image_to_window(cub3d->mlx, win->ptr, minimap->img.ptr, 0, 0);
}

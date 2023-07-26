/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:17:43 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 13:44:17 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "utils.h"

void	window_init(const t_cub3d *const cub3d, t_window *const win)
{
	t_image *const	screen = &win->screen;

	win->ptr = mlx_new_window(cub3d->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	_assert(win->ptr != NULL, "mlx_new_window() failed\n");
	screen->img = mlx_new_image(cub3d->mlx, WIN_WIDTH, WIN_HEIGHT);
	_assert(win->screen.img != NULL, "mlx_new_image() failed\n");
	screen->addr = mlx_get_data_addr(screen->img, &screen->bpp, &screen->len, \
		&screen->endian);
	_assert(screen->addr != NULL, "mlx_get_data_addr() failed\n");
}

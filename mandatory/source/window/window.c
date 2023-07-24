/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:17:43 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 12:53:37 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "utils.h"

void	init_window(t_config *const config, t_window *const win)
{
	win->ptr = mlx_new_window(config->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, PROGRAM);
	_assert(win->ptr != NULL, "mlx_new_window() failed\n");
	win->img = mlx_new_image(config->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	_assert(win->img != NULL, "mlx_new_image() failed\n");
	win->addr = mlx_get_data_addr(win->img, &win->bpp, &win->len, &win->endian);
	_assert(win->addr != NULL, "mlx_get_data_addr() failed\n");
}

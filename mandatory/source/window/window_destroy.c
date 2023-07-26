/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:32:13 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 13:49:20 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	window_destroy(const t_cub3d *const cub3d, t_window *const win)
{
	mlx_destroy_window(cub3d->mlx, win->ptr);
	image_destroy(cub3d, win->screen.img);
}

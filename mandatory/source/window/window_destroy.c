/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:32:13 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/27 03:35:18 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	window_destroy(const t_window *const win, void *mlx)
{
	mlx_destroy_window(mlx, win->ptr);
	image_destroy(win->img, mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:32:13 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 01:58:30 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	window_destroy(const t_window *const win, void *mlx)
{
	mlx_destroy_window(mlx, win->ptr);
	image_destroy(&win->img, mlx);
	image_destroy(&win->bg, mlx);
}

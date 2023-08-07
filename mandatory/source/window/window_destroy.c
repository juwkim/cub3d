/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:32:13 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/07 22:37:49 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	window_destroy(t_window *win, void *mlx)
{
	mlx_destroy_window(mlx, win->ptr);
	image_destroy(win->img, mlx);
	free(win);
}

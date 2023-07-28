/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:17:43 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/27 02:52:08 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

bool	window_init(t_window *const win, void *mlx)
{
	win->ptr = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, TITLE);
	if (win->ptr == NULL)
		return (false);
	if (image_init(win->img, mlx, WIN_WIDTH, WIN_HEIGHT) == false)
	{
		mlx_destroy_window(mlx, win->ptr);
		return (false);
	}
	return (win);
}

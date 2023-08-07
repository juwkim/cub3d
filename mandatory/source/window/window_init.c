/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:17:43 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/08 03:30:42 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

bool	window_init(t_window *const win, void *mlx)
{
	win->ptr = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, TITLE);
	if (win->ptr == NULL)
		return (false);
	if (image_init(&win->img, mlx, WIN_WIDTH, WIN_HEIGHT) == false)
	{
		mlx_destroy_window(mlx, win->ptr);
		return (false);
	}
	return (true);
}

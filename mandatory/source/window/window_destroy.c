/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:32:13 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 05:22:08 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	window_destroy(const t_window *const win, void *mlx)
{
	int	i;

	if (win->ptr)
		mlx_destroy_window(mlx, win->ptr);
	if (win->img.ptr)
		image_destroy(&win->img, mlx);
	if (win->bg.ptr)
		image_destroy(&win->bg, mlx);
	if (win->tex_id)
	{
		i = 0;
		while (i < WIN_HEIGHT && win->tex_id[i])
		{
			free(win->tex_id[i]);
			++i;
		}
		free(win->tex_id);
	}
}

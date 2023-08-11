/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_render_background.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:24:43 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 02:13:55 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	window_render_background(t_window *const win)
{
	int		i;
	int		j;
	t_color	*bg;

	j = 0;
	while (j < WIN_WIDTH)
	{
		i = 0;
		while (i < WIN_HEIGHT)
		{
			bg = image_address(&win->bg, i, j);
			*image_address(&win->img, i, j) = *bg;
			++i;
		}
		++j;
	}
}

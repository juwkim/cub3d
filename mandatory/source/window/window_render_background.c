/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_render_background.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:24:43 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 05:26:33 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	window_render_background(t_window *const win)
{
	int		i;
	int		j;
	t_color	*bg_addr;
	t_color	*img_addr;

	j = 0;
	while (j < WIN_WIDTH)
	{
		i = 0;
		while (i < WIN_HEIGHT)
		{
			bg_addr = image_address(&win->bg, i, j);
			img_addr = image_address(&win->img, i, j);
			*img_addr = *bg_addr;
			if (i < WIN_HEIGHT / 2)
				win->tex_id[i][j] = T_CEILING;
			else
				win->tex_id[i][j] = T_FLOOR;
			++i;
		}
		++j;
	}
}

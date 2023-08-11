/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render_background.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:24:43 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/09 14:25:38 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

void	texture_render_background(const t_texture *const tex, \
	t_window *const win)
{
	int		i;
	int		j;

	j = 0;
	while (j < WIN_WIDTH)
	{
		i = 0;
		while (i < WIN_HEIGHT / 2)
		{
			*image_address(&win->img, i, j) = tex->bgcolor[T_CEILING - N_BGPAD];
			++i;
		}
		while (i < WIN_HEIGHT)
		{
			*image_address(&win->img, i, j) = tex->bgcolor[T_FLOOR - N_BGPAD];
			++i;
		}
		++j;
	}
}

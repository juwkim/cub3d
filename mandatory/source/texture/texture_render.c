/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 02:08:22 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/08 21:35:47 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "image.h"

static void	texture_render_background(const t_texture *const tex, \
	t_window *const win);

void	texture_render(const t_texture *const tex, t_window *const win)
{
	texture_render_background(tex, win);
}

static void	texture_render_background(const t_texture *const tex, \
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

// static void	texture_render_wall(const t_texture *const tex, t_window *const win)
// {
// 	int		i;
// 	int		j;
// 	char	*p;
// 	t_color	color;
// 	t_ray	raycast;

// 	j = 0;
// 	while (j < WIN_WIDTH)
// 	{
// 		raycasting(cub3d, &cub3d->cam, \
// 			angle + AOF / 2 - AOF * j / WIN_WIDTH, &raycast);
// 		i = ft_max(0, raycast.start);
// 		while (i <= ft_min(WIN_HEIGHT, raycast.end))
// 		{
// 			p = win->img->addr + i * win->img->len + j * (win->img->bpp / 8);
// 			color = *(t_color *)(raycast.tex->addr + (TEX_HEIGHT - 1) * \
// 				(i - raycast.start) / (raycast.end - raycast.start) * \
// 				raycast.tex->len + raycast.off * raycast.tex->bpp / 8);
// 			*(t_color *)p = color;
// 			++i;
// 		}
// 		++j;
// 	}
// }
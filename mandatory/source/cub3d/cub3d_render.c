/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 04:44:24 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/31 07:39:23 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "texture.h"

static void	texture_render_background(const t_texture *const tex, \
	t_window *const win);
static void	texture_render_wall(t_cub3d *const cub3d, t_window *win, double angle);

void	cub3d_render(t_cub3d *const cub3d)
{
	t_window *const	win = &cub3d->win;

	texture_render_background(cub3d, win);
	texture_render_wall(cub3d, win, cub3d->cam.angle);
	mlx_put_image_to_window(cub3d->mlx, win->ptr, win->img, 0, 0);
}

static void	texture_render_background(const t_texture *const tex, \
	t_window *const win)
{
	int		i;
	int		j;
	char	*p;

	j = 0;
	while (j < WIN_WIDTH)
	{
		i = 0;
		while (i < WIN_HEIGHT / 2)
		{
			p = win->img->addr + i * win->img->len + j * (win->img->bpp / 8);
			*(t_color *)p = tex->bgcolor[T_CEILING];
			++i;
		}
		while (i < WIN_HEIGHT)
		{
			p = win->img->addr + i * win->img->len + j * (win->img->bpp / 8);
			*(t_color *)p = tex->bgcolor[T_FLOOR];
			++i;
		}
		++j;
	}
}

static void	texture_render_wall(const t_texture *const tex, t_window *const win)
{
	int		i;
	int		j;
	char	*p;
	t_color	color;
	t_ray	raycast;

	j = 0;
	while (j < WIN_WIDTH)
	{
		raycasting(cub3d, &cub3d->cam, \
			angle + AOF / 2 - AOF * j / WIN_WIDTH, &raycast);
		i = ft_max(0, raycast.start);
		while (i <= ft_min(WIN_HEIGHT, raycast.end))
		{
			p = win->img->addr + i * win->img->len + j * (win->img->bpp / 8);
			color = *(t_color *)(raycast.tex->addr + (TEX_HEIGHT - 1) * \
				(i - raycast.start) / (raycast.end - raycast.start) * \
				raycast.tex->len + raycast.off * raycast.tex->bpp / 8);
			*(t_color *)p = color;
			++i;
		}
		++j;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 04:44:24 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 04:19:14 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "raycasting.h"

static void	render_background(t_cub3d *cub3d, t_window *win);
static void	render_wall(t_cub3d *const cub3d, t_window *win, double lookat);

void	cub3d_render(t_cub3d *const cub3d)
{
	t_window *const	win = &cub3d->win;

	render_background(cub3d, win);
	render_wall(cub3d, win, cub3d->cam.lookat);
	mlx_put_image_to_window(cub3d->mlx, win->ptr, win->screen.img, 0, 0);
}

static void	render_background(t_cub3d *cub3d, t_window *win)
{
	int		i;
	int		j;
	char	*pixel;

	j = 0;
	while (j < WIN_WIDTH)
	{
		i = 0;
		while (i < WIN_HEIGHT / 2)
		{
			pixel = win->screen.addr + i * win->screen.len + j * (win->screen.bpp / 8);
			*(t_color *)pixel = cub3d->color[CEILING];
			++i;
		}
		while (i < WIN_HEIGHT)
		{
			pixel = win->screen.addr + i * win->screen.len + j * (win->screen.bpp / 8);
			*(t_color *)pixel = cub3d->color[FLOOR];
			++i;
		}
		++j;
	}
}

static void	render_wall(t_cub3d *const cub3d, t_window *win, double lookat)
{
	int			i;
	int			j;
	char		*pixel;
	t_color		color;
	t_raycast	raycast;

	j = 0;
	while (j < WIN_WIDTH)
	{
		raycasting(cub3d, &cub3d->cam, \
			lookat + AOF / 2 - AOF * j / WIN_WIDTH, &raycast);
		i = ft_max(0, raycast.start);
		while (i <= ft_min(WIN_HEIGHT, raycast.end))
		{
			pixel = win->screen.addr + i * win->screen.len + j * (win->screen.bpp / 8);
			color = *(t_color *)(raycast.tex->addr + (TEX_HEIGHT - 1) * \
				(i - raycast.start) / (raycast.end - raycast.start) * \
				raycast.tex->len + raycast.off * raycast.tex->bpp / 8);
			*(t_color *)pixel = color;
			++i;
		}
		++j;
	}
}

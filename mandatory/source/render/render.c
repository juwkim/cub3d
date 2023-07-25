/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 04:44:24 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/25 01:39:22 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "raycasting.h"

static void	render_background(t_config *config, t_window *win);
static void	render_wall(t_config *const config, t_window *win, double lookat);

void	render(t_config *config)
{
	t_window *const	win = &config->win;

	render_background(config, win);
	render_wall(config, win, config->cam.lookat);
	mlx_put_image_to_window(config->mlx, win->ptr, win->img, 0, 0);
}

static void	render_background(t_config *config, t_window *win)
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
			pixel = win->addr + i * win->len + j * (win->bpp / 8);
			*(t_color *)pixel = config->color[CEILING];
			++i;
		}
		while (i < WIN_HEIGHT)
		{
			pixel = win->addr + i * win->len + j * (win->bpp / 8);
			*(t_color *)pixel = config->color[FLOOR];
			++i;
		}
		++j;
	}
}

static void	render_wall(t_config *const config, t_window *win, double lookat)
{
	int			i;
	int			j;
	char		*pixel;
	t_color		color;
	t_raycast	raycast;

	j = 0;
	while (j < WIN_WIDTH)
	{
		raycasting(config, &config->cam, \
			lookat + AOF / 2 - AOF * j / WIN_WIDTH, &raycast);
		i = ft_max(0, raycast.start);
		while (i <= ft_min(WIN_HEIGHT, raycast.end))
		{
			pixel = win->addr + i * win->len + j * (win->bpp / 8);
			color = *(t_color *)(raycast.tex->addr + (TEX_HEIGHT - 1) * \
				(i - raycast.start) / (raycast.end - raycast.start) * \
				raycast.tex->len + raycast.off * raycast.tex->bpp / 8);
			*(t_color *)pixel = color;
			++i;
		}
		++j;
	}
}

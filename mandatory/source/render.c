/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 04:44:24 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 12:57:09 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "raycasting.h"

static void	render_background(t_config *config, t_window *win);
static void	render_wall(t_config *const config, t_window *win, double lookat);

void	render(t_config *config)
{
	render_background(config, &config->win);
	render_wall(config, &config->win, config->player.lookat);
	mlx_put_image_to_window(config->mlx_ptr, config->win.ptr, config->win.img, 0, 0);
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
	t_texture	tex;

	j = 0;
	while (j < WIN_WIDTH)
	{
		raycasting(config, lookat + AOF / 2 - AOF * j / WIN_WIDTH, &tex);
		i = tex.start;
		while (i <= tex.end)
		{
			if (0 <= i && i < WIN_HEIGHT)
			{
				pixel = win->addr + i * win->len + j * (win->bpp / 8);
				color = *(t_color *)(tex.img->addr + (TEX_HEIGHT - 1) * \
					(i - tex.start) / (tex.end - tex.start) * tex.img->len + \
					tex.off * tex.img->bpp / 8);
				*(t_color *)pixel = color;
			}
			++i;
		}
		++j;
	}
}

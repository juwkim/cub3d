/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 04:44:24 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/23 05:02:24 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "raycasting.h"

static void	render_background(t_game *game, t_img *screen);
static void	render_wall(t_game *const game, t_img *screen, double lookat);

void	render(t_game *game)
{
	render_background(game, &game->screen);
	render_wall(game, &game->screen, game->player.lookat);
	mlx_put_image_to_window(game->mlx, game->win, game->screen.pixels, 0, 0);
}

static void	render_background(t_game *game, t_img *screen)
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
			pixel = screen->addr + i * screen->len + j * (screen->bpp / 8);
			*(t_color *)pixel = game->color[CEILING];
			++i;
		}
		while (i < WIN_HEIGHT)
		{
			pixel = screen->addr + i * screen->len + j * (screen->bpp / 8);
			*(t_color *)pixel = game->color[FLOOR];
			++i;
		}
		++j;
	}
}

static void	render_wall(t_game *const game, t_img *screen, double lookat)
{
	int			i;
	int			j;
	char		*pixel;
	t_color		color;
	t_texture	tex;

	j = 0;
	while (j < WIN_WIDTH)
	{
		raycasting(game, lookat + AOF / 2 - AOF * j / WIN_WIDTH, &tex);
		i = tex.start;
		while (i <= tex.end)
		{
			if (0 <= i && i < WIN_HEIGHT)
			{
				pixel = screen->addr + i * screen->len + j * (screen->bpp / 8);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:11:01 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/23 01:30:03 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "event.h"
#include "utils.h"
#include "update.h"
#include "render.h"
#include "print.h"

static void	init(t_cub3d *const cub3d, t_img *const	screen);
static int	game_loop(t_cub3d *cub3d);

int	main(int argc, char *argv[])
{
	t_cub3d	cub3d;
	int		fd;

	_assert(argc == 2 && is_extension(argv[1], ".cub"), "Usage: .cub3D *.cub\n");
	fd = open(argv[1], O_RDONLY);
	_assert(fd != -1, strerror(errno));
	init(&cub3d, &cub3d.screen);
	parse_texture(&cub3d, fd);
	parse_map(&cub3d, fd);
	mlx_hook(cub3d.win, ON_KEYDOWN, KEY_PRESS_MASK, key_down, &cub3d.key);
	mlx_hook(cub3d.win, ON_KEYUP, KEY_RELEASE_MASK, key_up, &cub3d.key);
	mlx_hook(cub3d.win, ON_DESTORY, BUTTON_PRESS_MASK, destroy, &cub3d);
	mlx_loop_hook(cub3d.mlx, game_loop, &cub3d);
	mlx_loop(cub3d.mlx);
	return (EXIT_SUCCESS);
}

static void	init(t_cub3d *const cub3d, t_img *const	screen)
{
	ft_bzero(cub3d, sizeof(t_cub3d));
	cub3d->mlx = mlx_init();
	_assert(cub3d->mlx != NULL, "mlx_init() failed\n");
	cub3d->win = mlx_new_window(cub3d->mlx, WIN_WIDTH, WIN_HEIGHT, PROGRAM);
	_assert(cub3d->win != NULL, "mlx_new_window() failed\n");
	screen->pixels = mlx_new_image(cub3d->mlx, WIN_WIDTH, WIN_HEIGHT);
	_assert(screen->pixels != NULL, "mlx_new_image() failed\n");
	screen->addr = mlx_get_data_addr(screen->pixels, &screen->bpp, \
		&screen->len, &screen->endian);
	_assert(screen->addr != NULL, "mlx_get_data_addr() failed\n");
	cub3d->key.vertical = KEY_RELESED;
	cub3d->key.horizontal = KEY_RELESED;
	cub3d->key.rotation = KEY_RELESED;
	cub3d->map.capacity = 1024;
	cub3d->map.board = (char **)malloc(sizeof(char *) * cub3d->map.capacity);
	_assert(cub3d->map.board != NULL, "malloc() failed\n");
}

static int	game_loop(t_cub3d *cub3d)
{
	static bool	updated = true;

	if (updated)
		render(cub3d);
	updated = update(cub3d, &cub3d->key);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:11:01 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/23 06:07:05 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"
#include "event_bonus.h"
#include "utils_bonus.h"
#include "update_bonus.h"
#include "render_bonus.h"

static void	init(t_game *const game, t_img *const screen);
static int	game_loop(t_game *game);

int	main(int argc, char *argv[])
{
	t_game	game;
	int		fd;

	_assert(argc == 2 && is_extension(argv[1], ".cub"), "Usage: .game *.cub\n");
	fd = open(argv[1], O_RDONLY);
	_assert(fd != -1, strerror(errno));
	init(&game, &game.screen);
	parse_cub(&game, fd);
	mlx_hook(game.win, ON_KEYDOWN, KEY_PRESS_MASK, key_down, &game.key);
	mlx_hook(game.win, ON_KEYUP, KEY_RELEASE_MASK, key_up, &game.key);
	mlx_hook(game.win, ON_DESTORY, BUTTON_PRESS_MASK, destroy, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}

static void	init(t_game *const game, t_img *const	screen)
{
	ft_bzero(game, sizeof(t_game));
	game->mlx = mlx_init();
	_assert(game->mlx != NULL, "mlx_init() failed\n");
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, PROGRAM);
	_assert(game->win != NULL, "mlx_new_window() failed\n");
	screen->pixels = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	_assert(screen->pixels != NULL, "mlx_new_image() failed\n");
	screen->addr = mlx_get_data_addr(screen->pixels, &screen->bpp, \
		&screen->len, &screen->endian);
	_assert(screen->addr != NULL, "mlx_get_data_addr() failed\n");
	game->key.vertical = KEY_RELESED;
	game->key.horizontal = KEY_RELESED;
	game->key.rotation = KEY_RELESED;
	game->map.capacity = DEFAULT_MAP_CAPACITY;
	game->map.board = (char **)malloc(sizeof(char *) * game->map.capacity);
	_assert(game->map.board != NULL, "malloc() failed\n");
}

static int	game_loop(t_game *game)
{
	static bool	updated = true;

	if (updated)
		render(game);
	updated = update(game, &game->key);
	return (0);
}

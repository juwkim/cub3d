/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:11:01 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 12:57:25 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "window.h"
#include "event.h"
#include "utils.h"
#include "update.h"
#include "render.h"

static void	init_config(t_config *const cfg);
static int	cub3d(t_config *cfg);

int	main(int argc, char *argv[])
{
	t_config	cfg;

	_assert(argc == 2, "argc must be 2\n");
	init_config(&cfg);
	parse_cub(&cfg, argv[1]);
	mlx_hook(cfg.win.ptr, ON_KEYDOWN, KEY_PRESS_MASK, key_down, &cfg.key);
	mlx_hook(cfg.win.ptr, ON_KEYUP, KEY_RELEASE_MASK, key_up, &cfg.key);
	mlx_hook(cfg.win.ptr, ON_DESTORY, BUTTON_PRESS_MASK, destroy, &cfg);
	mlx_loop_hook(cfg.mlx_ptr, cub3d, &cfg);
	mlx_loop(cfg.mlx_ptr);
	return (EXIT_SUCCESS);
}

static void	init_config(t_config *const config)
{
	ft_bzero(config, sizeof(t_config));
	config->mlx_ptr = mlx_init();
	_assert(config->mlx_ptr != NULL, "mlx_init() failed\n");
	init_window(config, &config->win);
	config->key.vertical = KEY_RELESED;
	config->key.horizontal = KEY_RELESED;
	config->key.rotation = KEY_RELESED;
	config->map.capacity = DEFAULT_MAP_CAPACITY;
	config->map.board = (char **)malloc(sizeof(char *) * config->map.capacity);
	_assert(config->map.board != NULL, "malloc() failed\n");
}

static int	cub3d(t_config *config)
{
	static bool	updated = true;

	if (updated)
		render(config);
	updated = update(config, &config->key);
	return (0);
}

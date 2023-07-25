/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:11:01 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/25 16:29:18 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "cub.h"
#include "key.h"
#include "render.h"
#include "update.h"
#include "utils.h"
#include "window.h"

static void	init_config(t_config *const config);
static int	cub3d(t_config *const config);

int	main(int argc, char *argv[])
{
	t_config	config;

	_assert(argc == 2, "argc must be 2\n");
	init_config(&config);
	parse_cub(&config, argv[1]);
	mlx_hook(config.win.ptr, ON_KEYDOWN, KEY_PRESS_MASK, key_down, &config.key);
	mlx_hook(config.win.ptr, ON_KEYUP, KEY_RELEASE_MASK, key_up, &config.key);
	mlx_hook(config.win.ptr, ON_DESTORY, BUTTON_PRESS_MASK, destroy, &config);
	mlx_loop_hook(config.mlx, cub3d, &config);
	mlx_loop(config.mlx);
	return (EXIT_SUCCESS);
}

static void	init_config(t_config *const config)
{
	ft_bzero(config, sizeof(t_config));
	config->mlx = mlx_init();
	_assert(config->mlx != NULL, "mlx_init() failed\n");
	init_window(&config->win, config->mlx);
	init_key(&config->key);
}

static int	cub3d(t_config *const config)
{
	static bool	updated = true;

	if (updated)
		render(config);
	updated = update(config, &config->key);
	return (0);
}

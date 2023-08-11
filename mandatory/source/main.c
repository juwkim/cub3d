/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:11:01 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 02:36:52 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "key.h"
#include "utils.h"

int	main(int argc, char *argv[])
{
	t_cub3d			cub3d;
	t_window *const	win = &cub3d.win;

	if (argc != 2)
	{
		printf("Usage: ./cub3D *.cub\n");
		return (EXIT_FAILURE);
	}
	if (is_extension(argv[1], ".cub") == false)
	{
		printf("Error\n[%s] is not .cub file\n", argv[1]);
		return (EXIT_FAILURE);
	}
	if (cub3d_init(&cub3d, argv[1]) == false)
		return (EXIT_FAILURE);
	mlx_hook(win->ptr, KeyPress, KeyPressMask, key_press, &cub3d.key);
	mlx_hook(win->ptr, KeyRelease, KeyReleaseMask, key_release, &cub3d.key);
	mlx_hook(win->ptr, DestroyNotify, ButtonPressMask, cub3d_destroy, &cub3d);
	mlx_loop_hook(cub3d.mlx, cub3d_play, &cub3d);
	return (mlx_loop(cub3d.mlx));
}

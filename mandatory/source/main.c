/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:11:01 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/27 02:25:35 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_cub3d	cub3d;

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
	if (cub3d_init(&cub3d) == false)
		return (EXIT_FAILURE);
	mlx_hook(cub3d.win->ptr, KeyPress, KeyPressMask, key_press, cub3d.key);
	mlx_hook(cub3d.win->ptr, KeyRelease, KeyReleaseMask, key_release, \
		cub3d.key);
	mlx_hook(cub3d.win->ptr, DestroyNotify, ButtonPressMask, cub3d_end, &cub3d);
	mlx_loop_hook(cub3d.mlx, cub3d_start, &cub3d);
	return (mlx_loop(cub3d.mlx));
}

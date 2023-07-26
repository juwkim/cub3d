/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 03:27:03 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 04:22:33 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub3d_destroy(t_cub3d *const cub3d)
{
	int	i;

	i = 0;
	while (i < cub3d->map.height)
		free(cub3d->map.data[i++]);
	free(cub3d->map.data);
	mlx_destroy_image(cub3d->mlx, cub3d->tex[NORTH].img);
	mlx_destroy_image(cub3d->mlx, cub3d->tex[SOUTH].img);
	mlx_destroy_image(cub3d->mlx, cub3d->tex[WEST].img);
	mlx_destroy_image(cub3d->mlx, cub3d->tex[EAST].img);
	mlx_destroy_image(cub3d->mlx, cub3d->win.screen.img);
	mlx_destroy_window(cub3d->mlx, cub3d->win.ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

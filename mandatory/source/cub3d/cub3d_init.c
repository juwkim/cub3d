/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:54:13 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 13:27:05 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub.h"
#include "window.h"
#include "key.h"
#include "utils.h"

bool	cub3d_init(t_cub3d *const cub3d, const char *filename)
{
	ft_bzero(cub3d, sizeof(t_cub3d));
	cub3d->mlx = mlx_init();
	if (cub3d->mlx == NULL)
	{
		perror("mlx_init()");
		return (false);
	}
	window_init(cub3d, &cub3d->win);
	key_init(cub3d, &cub3d->key);
	parse_cub(cub3d, filename);
	mlx_hook(cub3d->win.ptr, DestroyNotify, ButtonPressMask, cub3d_destroy, cub3d);
	mlx_loop_hook(cub3d->mlx, cub3d_play, cub3d);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 03:57:34 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 11:32:29 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

void	key_init(const t_cub3d *cub3d, t_key *const key)
{
	key->vertical = KEY_RELESE;
	key->horizontal = KEY_RELESE;
	key->rotation = KEY_RELESE;
	mlx_hook(cub3d->win.ptr, KeyPress, KeyPressMask, key_press, key);
	mlx_hook(cub3d->win.ptr, KeyRelease, KeyReleaseMask, key_release, key);
}

int	key_press(int keycode, t_key *const key)
{
	if (keycode == KEY_W || keycode == KEY_S)
		key->vertical = keycode;
	else if (keycode == KEY_A || keycode == KEY_D)
		key->horizontal = keycode;
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		key->rotation = keycode;
	else if (keycode == KEY_ESC)
		key->esc = true;
	return (0);
}

int	key_release(int keycode, t_key *const key)
{
	if (key->vertical == keycode)
		key->vertical = KEY_RELESE;
	else if (key->horizontal == keycode)
		key->horizontal = KEY_RELESE;
	else if (key->rotation == keycode)
		key->rotation = KEY_RELESE;
	return (0);
}

int	destroy(t_cub3d *const cub3d)
{
	int	i;

	mlx_destroy_image(cub3d->mlx, cub3d->win.screen.img);
	mlx_destroy_image(cub3d->mlx, cub3d->tex[NORTH].img);
	mlx_destroy_image(cub3d->mlx, cub3d->tex[SOUTH].img);
	mlx_destroy_image(cub3d->mlx, cub3d->tex[WEST].img);
	mlx_destroy_image(cub3d->mlx, cub3d->tex[EAST].img);
	mlx_destroy_window(cub3d->mlx, cub3d->win.ptr);
	i = 0;
	while (i < cub3d->map.height)
		free(cub3d->map.data[i++]);
	free(cub3d->map.data);
	exit(EXIT_SUCCESS);
	return (0);
}

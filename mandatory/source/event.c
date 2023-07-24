/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 03:57:34 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/24 12:53:09 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

int	key_down(int keycode, t_key *const key)
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

int	key_up(int keycode, t_key *const key)
{
	if (key->vertical == keycode)
		key->vertical = KEY_RELESED;
	else if (key->horizontal == keycode)
		key->horizontal = KEY_RELESED;
	else if (key->rotation == keycode)
		key->rotation = KEY_RELESED;
	return (0);
}

int	destroy(t_config *const config)
{
	mlx_destroy_image(config->mlx_ptr, config->win.img);
	mlx_destroy_image(config->mlx_ptr, config->img[NORTH].pixels);
	mlx_destroy_image(config->mlx_ptr, config->img[SOUTH].pixels);
	mlx_destroy_image(config->mlx_ptr, config->img[WEST].pixels);
	mlx_destroy_image(config->mlx_ptr, config->img[EAST].pixels);
	mlx_destroy_window(config->mlx_ptr, config->win.ptr);
	free(config->map.board);
	exit(EXIT_SUCCESS);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 03:57:34 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:41:46 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_bonus.h"

int	key_press(const int keycode, t_cub3d *const cub3d)
{
	t_key *const	key = &cub3d->key;
	t_mouse *const	mouse = &cub3d->mouse;

	if (keycode == KEY_W || keycode == KEY_S)
		key->vertical = keycode;
	else if (keycode == KEY_A || keycode == KEY_D)
		key->horizontal = keycode;
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		key->rotation = keycode;
	else if (keycode == KEY_ESC)
		key->esc = true;
	else if (keycode == KEY_P)
		mouse->window_rotatable ^= 1;
	return (0);
}

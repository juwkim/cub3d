/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 03:57:34 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 18:58:23 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

int	key_press(const int keycode, t_key *const key)
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

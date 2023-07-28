/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 03:57:34 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/26 18:58:27 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

int	key_release(const int keycode, t_key *const key)
{
	if (key->vertical == keycode)
		key->vertical = KEY_RELESE;
	else if (key->horizontal == keycode)
		key->horizontal = KEY_RELESE;
	else if (key->rotation == keycode)
		key->rotation = KEY_RELESE;
	return (0);
}

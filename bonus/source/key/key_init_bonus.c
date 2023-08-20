/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 03:57:34 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:41:44 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_bonus.h"

bool	key_init(t_key *const key, const double rotation_speed, \
	const double moving_speed)
{
	key->vertical = KEY_RELESE;
	key->horizontal = KEY_RELESE;
	key->rotation = KEY_RELESE;
	key->esc = false;
	key->rotation_speed = rotation_speed;
	key->moving_speed = moving_speed;
	return (true);
}

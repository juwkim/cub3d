/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 03:57:34 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/20 17:41:48 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_bonus.h"

int	key_release(const int keycode, t_key *const key)
{
	if (key->vertical == (enum e_key)keycode)
		key->vertical = KEY_RELESE;
	else if (key->horizontal == (enum e_key)keycode)
		key->horizontal = KEY_RELESE;
	else if (key->rotation == (enum e_key)keycode)
		key->rotation = KEY_RELESE;
	return (0);
}

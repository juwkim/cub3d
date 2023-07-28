/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 03:57:34 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/27 02:55:05 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

bool	key_init(t_key *const key)
{
	key->vertical = KEY_RELESE;
	key->horizontal = KEY_RELESE;
	key->rotation = KEY_RELESE;
	key->esc = false;
	return (true);
}

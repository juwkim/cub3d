/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 03:57:34 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/08 00:07:47 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

bool	key_init(t_key **key)
{
	*key = malloc(sizeof(t_key));
	if (*key == NULL)
		return (false);
	(*key)->vertical = KEY_RELESE;
	(*key)->horizontal = KEY_RELESE;
	(*key)->rotation = KEY_RELESE;
	(*key)->esc = false;
	return (true);
}

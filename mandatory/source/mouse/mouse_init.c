/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:33:49 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/08 00:07:56 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse.h"

bool	mouse_init(t_mouse **mouse, const double rotate_speed)
{
	*mouse = malloc(sizeof(t_mouse));
	if (*mouse == NULL)
		return (false);
	(*mouse)->rotation_speed = rotate_speed;
	return (true);
}
